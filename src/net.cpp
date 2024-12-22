#include "net.hpp"

#include <arpa/inet.h>
#include <fstream>

std::string net::ulToIP(unsigned long address){
	struct in_addr addr;
	addr.s_addr = address; 
	return std::string(inet_ntoa(addr));
}

net::node net::getNode(std::string input, std::string protocol){
	return{
		protocol,
		ulToIP(std::stoul(input.substr(0, 8), nullptr, 16)),
		std::to_string(std::stoul(input.substr(9, 4), nullptr, 16)),
		ulToIP(std::stoul(input.substr(14, 8), nullptr, 16)),
		std::to_string(std::stoul(input.substr(23, 4), nullptr, 16)),
		input.substr(28, 2)
	};
}

void net::getConnections(std::string source, std::string protocol){
	unsigned int lineNumber = 0;
	std::ifstream stream(source);

	for(std::string line; std::getline(stream, line);){
		if(lineNumber > 0){
			net::nodes.push_back(getNode(line.substr(line.find(":")+2), protocol));
		}
		lineNumber++;
	}

	stream.close();
}

void net::update(){
	net::nodes.clear();

	getConnections("/proc/net/tcp", "tcp");
	getConnections("/proc/net/udp", "udp");
 }
