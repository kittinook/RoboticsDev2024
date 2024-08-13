#!/usr/bin/python3

class PIDController:
    def __init__(self, Kp, Ki, Kd, Umax):
        # PID Coefficients
        self.a0 = Kp + Ki + Kd
        self.a1 = Kp + 2 * Kd
        self.a2 = Kd

        # PID State
        self.ek_1 = 0.0
        self.ek_2 = 0.0
        self.u = 0.0
        self.u_max = Umax

    def set_param(self, Kp, Ki, Kd, Umax):
        self.a0 = Kp + Ki + Kd
        self.a1 = Kp + 2 * Kd
        self.a2 = Kd
        self.u_max = Umax

    def compute(self, ek):
        # Compute the PID control signal
        if abs(self.u) < self.u_max or ek <= 0 and ek >= 0:
            self.u += self.a0 * ek - self.a1 * self.ek_1 + self.a2 * self.ek_2
        
        # Update error states
        self.ek_2 = self.ek_1
        self.ek_1 = ek

        # Saturate the output
        return max(min(self.u, self.u_max), -self.u_max)