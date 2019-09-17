//TCP
	/*sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::TcpSocket tcpSocket;
	char connectionType;
	char mode;
	char buffer[2000];
	std::size_t received;
	std::string text = "Connected to: ";
	cout << "Enter (s) for Server, Enter (c) for Client" << "\n";
	cin >> connectionType;

	//UDP
	std::map<unsigned short, sf::IpAddress> computerID;
	unsigned short port;
	sf::UdpSocket udpSocket;
	std::cout << "Set port number: ";
	cin >> port;
	udpSocket.bind(port);*/

	/*if (connectionType == 's')
	{
		sf::TcpListener listener;
		listener.listen(45000);
		listener.accept(tcpSocket);
		text += "Server";
		mode = 's';
	}
	else if (connectionType == 'c')
	{
		tcpSocket.connect(ip,45000);
		text += "Client";
		mode = 'r';
	}

	tcpSocket.send(text.c_str(), text.length() + 1);
	tcpSocket.receive(buffer, sizeof(buffer), received);
	std::cout << buffer << "\n";

	bool done = false;

	while (!done)
	{
		if (mode == 's')
		{
			std::getline(cin, text);
			tcpSocket.send(text.c_str(), text.length() + 1);
			mode = 'r';
		}
		else if (mode == 'r')
		{
			tcpSocket.receive(buffer, sizeof(buffer), received);
			if (received > 0)
			{
				cout << "Received: " << buffer << "\n";
				mode = 's';
			}
		}
	}*/

	/*if (connectionType == 's')
	{
		char answer = 'b';
		do
		{
			sf::IpAddress rIp;
			unsigned short port;
			udpSocket.receive(buffer, sizeof(buffer), received, rIp, port);
			if (received > 0)
			{
				computerID[port] = rIp;
			}
			cin >> answer;
		}
		while (answer != 'a');
	}
	else
	{
		string sIp;
		cout << "Enter server ip: ";
		char c;
		while (true)
		{
			c = (char)_getch();
			if (c == 13)
			{
				break;
			}
			sIp += c;
			cout << "*";
		}
		sf::IpAddress sendIp(sIp);
		udpSocket.send(text.c_str(), text.length() + 1, sendIp, 45000);
	}

	bool done = false;

	while (!done)
	{
		if (connectionType == 's')
		{
			getline(cin, text);
			std::map<unsigned short, sf::IpAddress>::iterator tempIterator;
			for (tempIterator = computerID.begin(); tempIterator != computerID.end(); tempIterator++)
			{
				udpSocket.send(text.c_str(), text.length() +1, tempIterator->second, tempIterator->first);
			}
		}
		else
		{
			sf::IpAddress tempIp;
			unsigned short tempPort;
			udpSocket.receive(buffer, sizeof(buffer), received, tempIp, tempPort);
			if (received > 0)
			{
				cout << "Received: " << buffer << "\n";
			}
		}
	}*/