#pragma once

#include <glut/glut.h>
#include <tdogl/Program.h>
#include <tdogl/Texture.h>

#include "../mouse/IMouseAlgorithm.h"
#include "MazeGraphic.h"
#include "Mouse.h"
#include "MouseGraphic.h"
#include "MouseInterface.h"
#include "TextDrawer.h"
#include "World.h"

namespace sim {

class Driver {

public:

    // The Driver class is not constructible
    Driver() = delete;

    // The name "drive" is just supposed to be punny
    static void drive(int argc, char* argv[]);

private:

    // Simulation objects
    static Maze* m_maze;
    static Mouse* m_mouse;
    static MazeGraphic* m_mazeGraphic;
    static MouseGraphic* m_mouseGraphic;
    static MouseInterface* m_mouseInterface;
    static World* m_world;

    // Micromouse algorithm object
    static IMouseAlgorithm* m_algorithm;

    // Text drawing object
    static TextDrawer* m_textDrawer;

    // Polygon program variables
    static tdogl::Program* m_polygonProgram;
    static GLuint m_polygonVertexArrayObjectId;
    static GLuint m_polygonVertexBufferObjectId;

    // Texture program variables
    static tdogl::Texture* m_textureAtlas;
    static tdogl::Program* m_textureProgram;
    static GLuint m_textureVertexArrayObjectId;
    static GLuint m_textureVertexBufferObjectId;

    // Set up logging, State, and Param
    static void bootstrap();

    // Initialize all of the simulation objects
    static void initModel();
    static void validateMouseAlgorithm(const std::string& mouseAlgorithm);
    static void validateMouseInterfaceType(
        const std::string& mouseAlgorithm, const std::string& interfaceType);
    static void validateMouseInitialDirection(
        const std::string& mouseAlgorithm, const std::string& initialDirection);
    static void validateMouseWheelSpeedFraction(
        const std::string& mouseAlgorithm, double wheelSpeedFraction);
    static void initAndValidateMouse(
        const std::string& mouseAlgorithm, const std::string& mouseFile,
        InterfaceType interfaceType, Direction initialDirection, Mouse* mouse);

    // Callback functions
    static void draw();
    static void keyPress(unsigned char key, int x, int y);
    static void specialKeyPress(int key, int x, int y);
    static void specialKeyRelease(int key, int x, int y);

    // Initialize all of the graphics
    static void initPolygonProgram();
    static void initTextureProgram();
    static void initGraphics(int argc, char* argv[]);

    // Drawing helper methods
    static void repopulateVertexBufferObjects();
    static void drawFullAndZoomedMaps(
        const Coordinate& currentMouseTranslation, const Angle& currentMouseRotation,
        tdogl::Program* program, int vaoId, int vboStartingIndex, int vboEndingIndex);
};

} // namespace sim
