from setuptools import find_packages
from setuptools import setup

setup(
    name='motorsim_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('motorsim_interfaces', 'motorsim_interfaces.*')),
)
