#include "graphics.hpp"
#include "net.hpp"

void graphics::display(){
	net::update();

	InitWindow(1280, 720, "ioaware");

	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(BLACK);

		if(int(GetTime()) % 4 == 0){
			net::update();
		}

		unsigned int i = 0;	

		for(net::node n : net::nodes){
			std::string output;
			output.append("proto: ").append(n.protocol).append(" ");
			output.append("local: ").append(n.localAddress).append(" ");
			output.append("localPort: ").append(n.localPort).append(" ");
			output.append("remote: ").append(n.remoteAddress).append(" ");
			output.append("remotePort: ").append(n.remotePort).append(" ");
			output.append("state: ").append(n.state);

			DrawText(output.c_str(), 20, 20 + i*20, 20, WHITE);
			i++;
		}

		EndDrawing();
	}

	CloseWindow();
}
