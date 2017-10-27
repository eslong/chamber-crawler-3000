CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = test
OBJECTS = game.o cell.o Character.o door.o dwarf.o elf.o enemy.o floor.o GObject.o halfling.o human.o orc.o merchant.o room.o test.o textdisplay.o treasure.o healthpotion.o player.o shade.o stairs.o preset.o dragon.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
