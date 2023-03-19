#solved

class GardenSim:
    _gardenSections = []
    _wateredSections = []
    _n = 0

    def parseInput(self):
        self._n = int(input())
        self._gardenSections = list(map(int, input().split()))
        for _ in range(self._n):
            self._wateredSections.append(1)
    
    def __init__(self) -> None:
        self.parseInput()

    def simulateRightSide(self, section):
        currSection = section
        nextSection = section + 1
        while(nextSection < self._n):
            if(self._gardenSections[nextSection] <= self._gardenSections[currSection]):
                self._wateredSections[section] += 1
                currSection = nextSection
                nextSection += 1
            else:
                break
    
    def simulateLeftSide(self, section):
        currSection = section
        nextSection = section - 1
        while(nextSection >= 0):
            if(self._gardenSections[nextSection] <= self._gardenSections[currSection]):
                self._wateredSections[section] += 1
                currSection = nextSection
                nextSection -= 1
            else:
                break

    def runSimulation(self):
        for section in range(self._n):
            self.simulateLeftSide(section)
            self.simulateRightSide(section)
        return max(self._wateredSections)



sim = GardenSim()

print(sim.runSimulation())