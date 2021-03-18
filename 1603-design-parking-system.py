class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.positions = big | medium << 10 | small << 20

    def addCar(self, carType: int) -> bool:
        bits = (carType-1)*10
        if self.positions >> bits & 1023:
            self.positions -= 1 << bits
            return True
        return False


# Your ParkingSystem object will be instantiated and called as such:
# parkingSystem = ParkingSystem(1, 1, 0)
# print(parkingSystem.addCar(1))
# print(parkingSystem.addCar(2))
# print(parkingSystem.addCar(3))
# print(parkingSystem.addCar(1))
