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

		static const inline std::vector<std::string> tcpStates{
			"DUMMY",
			"ESTABLISHED",
			"SYN_SENT",
			"SYN_RECV",
			"FIN_WAIT1",
			"FIN_WAIT2",
			"TIME_WAIT",
			"CLOSE",
			"CLOSE_WAIT",
			"LAST_ACK",
			"LISTEN",
			"CLOSING",
			"NEW_SYN_RECV",
			"MAX_STATES"
		};

		static inline std::vector<node> nodes;
		static void update(void);
	private:
		static node getNode(std::string, std::string);
		static void getConnections(std::string, std::string);
		static std::string ulToIP(unsigned long);
};
