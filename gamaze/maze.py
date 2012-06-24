__author__ = 'danny'

from gamaze.point import Point
import logging

class Maze(object):
    """A simple representation of a fixed maze"""

    def __init__(self):
        self._decisionReward = 0
        self._revisitDecisionPenalty = 0
        self._goalReward = 0
        self._outOfBoundsPenalty = 0
        self._north = Point(0, -1)
        self._south = Point(0, 1)
        self._east = Point(1, 0)
        self._west = Point(-1, 0)
        self._start = Point(0, 0)

        self._geneTypes = {
            "N": self._north,
            "S": self._south,
            "E": self._east,
            "W": self._west
        }

        self._dirTable = {self._north: (self._east, self._west, self._south),
                         self._south: (self._east, self._west, self._north),
                         self._east: (self._north, self._south, self._west),
                         self._west: (self._north, self._south, self._east)}

        self._mazeRep = ("D D D  #",
                        " # # ###",
                        " ### ## ",
                        "D # D  D",
                        " ## ### ",
                        "  # # D ",
                        "#D D # #",
                        "  ## # G")
        self._width = 8
        self._height = 8

    def withDecisionReward(self, dR):
        self._decisionReward = dR
        return self

    def withGoalReward(self, gR):
        self._goalReward = gR
        return self

    def withRevisitPenalty(self, rP):
        self._revisitDecisionPenalty = rP
        return self

    def withOutOfBoundsPenalty(self, oP):
        self._outOfBoundsPenalty = oP
        return self

    @property
    def genes(self):
        """Return the possible genes"""
        return self._geneTypes.keys()

    def _getCellAt(self, position):
        """Get the information for the maze at the location"""
        return self._mazeRep[position.y][position.x]

    def _isDecisionOrRewardAt(self, position):
        """Returns true if the location is a decision point,
        or reward point"""
        return self._getCellAt(position) in "DG"

    def _isInBounds(self, position):
        """Ensure the given position is inside the maze boundaries"""
        return ( 0 <= position.y < self._height and
                 0 <= position.x < self._width)

    def _isWallAt(self, position):
        """Return true if there is a wall at the queried position"""
        return not self._isInBounds(position) or self._getCellAt(position) == "#"

    def _isDecisionPointAt(self, position):
        """Return true if the position is a decision point"""
        return self._getCellAt(position) == "D"

    def _isGoalAt(self, position):
        return self._getCellAt(position) == "G"

    def _findOpening(self, position, direction):
        """Find the direction with the opening. Worst case - turn back around"""
        for newdir in self._dirTable[direction]:
            newPosition = position + newdir
            if not self._isWallAt(newPosition):
                return newPosition, newdir

    def _findNextDecision(self, position, direction, _cache = {}):
        """Find a decision point based on the current position and direction.
        position: a 2-d coord Point
        direction: a 2-d direction Point
        returns: a 2-d coord Point
        """
        orig = (hash(position), hash(direction))
        if orig in _cache:
            return _cache[orig]

        newdir = direction
        position += newdir
        while not self._isDecisionOrRewardAt(position):
            self._logMaze(position, newdir)
            newPosition = position + newdir
            if not self._isWallAt(newPosition):
                position = newPosition
            else:
                position, newdir = self._findOpening(position, newdir)
        _cache[orig] = (position, newdir)

        return position, newdir

    def _logMaze(self, position, direction, showLog = (logging.getLogger().level is logging.DEBUG) ):
        """Log a maze - with an X at the position given"""
        if showLog:
            logging.debug("**** MAZE:")
            playerDir = {self._north: "^",
                         self._south: ",",
                         self._east: ">",
                         self._west: "<"}

            for y, row in enumerate(self._mazeRep):
                if position.y == y:
                    row = row[:position.x] + playerDir[direction] + row[position.x+1:]
                logging.debug("   %s", row)
            logging.debug("****")

    def testIndividual(self, genes):
        """Given a genotype (set of NSEW genes),
        try them from the starting point in the maze
        and return the fitness score"""
        position = self._start
        fitness = 0
        visitedDecisionPoints = [self._start]
        logging.info("Testing genes %s", repr(genes))
        for gene in genes:
            direction = self._geneTypes[gene]
            self._logMaze(position, direction)
            newPosition = position + direction
            #Penalise being out of bounds
            if not self._isInBounds(newPosition):
                logging.debug("Out of bounds. Fitness = %d - %d = %d", fitness, self._outOfBoundsPenalty, fitness - self._outOfBoundsPenalty)
                fitness -= self._outOfBoundsPenalty
            else:
                #Or go to the next position
                position, direction = self._findNextDecision(position, direction)
                self._logMaze(position, direction)

            #Penalise revisiting decision point, reward progress
            if self._isDecisionPointAt(position):
                if position in visitedDecisionPoints:
                    logging.debug("Revisiting. Fitness = %d - %d = %d", fitness, self._revisitDecisionPenalty, fitness - self._revisitDecisionPenalty)
                    fitness -= self._revisitDecisionPenalty
                else:
                    logging.debug("New decision point. Fitness = %d + %d = %d", fitness, self._decisionReward, fitness + self._decisionReward)
                    fitness += self._decisionReward
                    visitedDecisionPoints.append(position)

            #Reward the goal condition
            if self._isGoalAt(position):
                logging.debug("Goal. Fitness = %d + %d = %d", fitness, self._goalReward, fitness + self._goalReward)
                fitness += self._goalReward
                break

            fitness = max(0, fitness)

        return fitness
