#!/usr/bin/python3

class DCMotorModel:
    def __init__(self, Ke, Kt, L, R, J, B, V_max):
        # DC Motor Constants
        self.Ke = Ke
        self.Kt = Kt
        self.L = L
        self.R = R
        self.J = J
        self.B = B
        self.V_max = V_max

        # DC Motor Coefficients
        self.a0 = self.a1 = self.a2 = 0.0
        self.b0 = self.b1 = self.b2 = 0.0

        # DC Motor States
        self.qdk_1 = 0.0
        self.ik_1 = 0.0

    def init_common(self, _freq):
        # Common initialization values
        freq_div = self.R + self.L * _freq
        inv_Kt = 1.0 / self.Kt

        return freq_div, inv_Kt

    def IM_init(self, _freq):
        freq_div, inv_Kt = self.init_common(_freq)

        self.a0 = self.J * _freq * inv_Kt
        self.a1 = self.a0 + self.B * inv_Kt
        self.a2 = inv_Kt

        self.b0 = self.L * _freq
        self.b1 = self.b0 + self.R
        self.b2 = self.Ke

    def FM_init(self, _freq):
        freq_div, _ = self.init_common(_freq)

        inv_freq_div = 1.0 / freq_div

        self.a0 = inv_freq_div
        self.a1 = self.Ke * inv_freq_div
        self.a2 = self.L * _freq * inv_freq_div

        inv_J_freq = 1.0 / (self.J * _freq)
        self.b0 = inv_J_freq
        self.b1 = self.Kt * inv_J_freq
        self.b2 = 1.0 - self.B * inv_J_freq

    def IM_compute(self, _qd, _Tl):
        ik = self.a2 * _Tl + self.a1 * _qd - self.a0 * self.qdk_1
        uk = self.b2 * _qd + self.b1 * ik - self.b0 * self.ik_1

        self.ik_1 = ik
        self.qdk_1 = _qd

        return max(min(uk, self.V_max), -self.V_max)

    def FM_compute(self, _uk, _Tl):
        _uk = max(min(_uk, self.V_max), -self.V_max)

        ik = self.a2 * self.ik_1 - self.a1 * self.qdk_1 + self.a0 * _uk
        qd = self.b2 * self.qdk_1 + self.b1 * ik - self.b0 * _Tl

        self.ik_1 = ik
        self.qdk_1 = qd
        return qd
