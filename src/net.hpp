#pragma once

#include <string>
#include <vector>

class net{
	public:
		struct node{
			std::string protocol;
			std::string localAddress;
			std::string localPort;
			std::string remoteAddress;
			std::string remotePort;
			std::string state;
		};

		static inline std::vector<node> nodes;
		static void update(void);
	private:
		static node getNode(std::string, std::string);
		static void getConnections(std::string, std::string);
		static std::string ulToIP(unsigned long);
};
