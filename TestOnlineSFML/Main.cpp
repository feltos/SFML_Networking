#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <iostream>

using namespace std;

int main()
{	
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::TcpSocket socket;
	char connectionType;

	std::cout << "(s) for server, (c) for client: ";
	std::cin >> connectionType;

	if (connectionType == 's')
	{
		sf::TcpListener listener;
		listener.listen(45000);
		listener.accept(socket);
	}
	else
	{
		socket.connect(ip,45000);
	}

	sf::RectangleShape rect1;
	sf::RectangleShape rect2;

	rect1.setSize(sf::Vector2f(20, 20));
	rect2.setSize(sf::Vector2f(20, 20));

	rect1.setFillColor(sf::Color::Red);
	rect2.setFillColor(sf::Color::Blue);

	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Packets");

	sf::Vector2f prevPosition;
	sf::Vector2f p2Position;

	socket.setBlocking(false);

	bool update = false;

	while (window.isOpen())
	{
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed || Event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
			else if (Event.type == sf::Event::GainedFocus)
			{
				update = true;
			}
			else if (Event.type == sf::Event::LostFocus)
			{
				update = false;
			}
		}

		prevPosition = rect1.getPosition();
		if (update)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				rect1.move(0.5f, 0.0f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				rect1.move(-0.5f, 0.0f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				rect1.move(0.0f, -0.5f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				rect1.move(0.0f, 0.5f);
		}
		sf::Packet packet;

		if (prevPosition != rect1.getPosition())
		{
			packet << rect1.getPosition().x << rect1.getPosition().y;
			socket.send(packet);
		}

		socket.receive(packet);
		if (packet >> p2Position.x >> p2Position.y)
		{
			rect2.setPosition(p2Position);
		}

		window.draw(rect1);
		window.draw(rect2);

		window.display();
		window.clear();
	}

	system("pause");
	return 0;
}