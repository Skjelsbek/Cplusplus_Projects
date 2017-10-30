#include <winsock2.h>
#include <Ws2tcpip.h>
#include <iostream>
#include <string>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

int main()
{			
	// Initialize Winsock	
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {
		std::cerr << "WSAStartup failed with error: " << iResult << std::endl;
		return 1;
	}

	// Create a socket for sending data
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) {
		std::cerr << "socket failed with error: " << WSAGetLastError() << std::endl;
		WSACleanup();
		return 1;
	}
	
	// Set up the server structure with the IP address of the server
	// and the specified port number.
	std::string ipAddr = "192.168.1.2";
	unsigned short port = 27015;
	sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	inet_pton(AF_INET, ipAddr.c_str(), &server.sin_addr);

	// Connecting to server
	iResult = connect(sock, (sockaddr*)&server, sizeof(server));
	if (iResult == SOCKET_ERROR)
	{
		std::cerr << "Can't connect to server, error: " << WSAGetLastError() << std::endl;
		closesocket(sock);
		WSACleanup();
		return 1;
	}

	// Send and receive data
	char buffer[1024];
	int bufLen = 1024;
	std::string userInput;
	
	// Sending user input, and receiving response from server
	do
	{
		// User input prompt
		std::cout << ">";
		getline(std::cin, userInput);
		
		if (userInput.size() > 0)
		{
			// Sending user input
			int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);

			// Check the return value of send function to see if the transfer was successful
			if (sendResult != SOCKET_ERROR)
			{
				// Clear buffer and receive response from server
				ZeroMemory(buffer, bufLen);
				int bytesReceived = recv(sock, buffer, bufLen, 0);

				// Print response if something was received
				if (bytesReceived > 0)
				{
					std::cout << "Server>" << std::string(buffer, 0, bytesReceived) << std::endl;					
				}
			}
		}
	} while (userInput.size() > 0); // HUSK � BYTTE UT DENNE HER!
	
	// Clean up and quit.
	std::cout << "Exiting" << std::endl;
	closesocket(sock);
	WSACleanup();
	return 0;
}