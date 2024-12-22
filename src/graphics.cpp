#include "graphics.hpp"
#include "net.hpp"
#include <math.h>

void graphics::display(){
	net::update();

	InitWindow(1280, 720, "ioaware");

	Camera3D camera;
	Vector3 camPos{10.0f, 10.0f, 10.0f};
	camera.position = camPos;
	Vector3 camTarget{0.0f, 0.0f, 0.0f};
	camera.target = camTarget;
	Vector3 camUp{0.0f, 1.0f, 0.0f};
	camera.up = camUp;
	camera.fovy = 90.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	DisableCursor();

	while(!WindowShouldClose()){
        UpdateCamera(&camera, CAMERA_ORBITAL);
		BeginDrawing();
		ClearBackground(BLACK);

		if(int(GetTime()) % 2 == 0){
			net::update();
		}

		BeginMode3D(camera);
		for(int i=0; i<360; i+=360/net::nodes.size()){
			float x = cos(i*(PI/180))*10.0f, y = 0.0f, z = sin(i*(PI/180))*10.0f;
			Vector3 p{x, y, z};
			DrawCube(p, 1.0f, 1.0f, 1.0f, RED);
		}
		EndMode3D();

		unsigned int i = 0;	

		for(net::node n : net::nodes){
			std::string output;
			output.append("proto: ").append(n.protocol).append(" ");
			output.append("local: ").append(n.localAddress).append(" ");
			output.append("localPort: ").append(n.localPort).append(" ");
			output.append("remote: ").append(n.remoteAddress).append(" ");
			output.append("remotePort: ").append(n.remotePort).append(" ");
			output.append("state: ").append(n.state);

			DrawText(output.c_str(), 20, 20 + i*10, 10, WHITE);
			i++;
		}

		EndDrawing();
	}

	CloseWindow();
}
