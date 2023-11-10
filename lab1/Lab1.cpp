#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

class AnimatedText
{
private:

    int m_time = 0;
    float m_OneSymbolTime = 0;

public:

    std::string m_Str = "";

    AnimatedText(const std::string& Str, int time)
    {
        m_Str = Str;
        m_time = time;
    }

    void Timing()
    {
        m_OneSymbolTime = (float(m_time) * 1000000 / m_Str.length());
    }

    void Sleep() const
    {
        std::this_thread::sleep_for(std::chrono::microseconds(int(m_OneSymbolTime)));
    }

};

int main()
{
    std::string str;
    std::getline(std::cin, str);

    int time;
    std::cin >> time;

    AnimatedText AT(str, time);

    AT.Timing();

    AnimatedText SfmlAT(str, time);
    
    sf::RenderWindow window(sf::VideoMode(500, 500), "AimatedTest");

    sf::Text TEXT;
    sf::Font FONT;

    FONT.loadFromFile("times.ttf");
    TEXT.setFont(FONT);
    TEXT.setFillColor(sf::Color::Blue);
    TEXT.setStyle(sf::Text::Bold);
    TEXT.setCharacterSize(35);
    TEXT.setString(SfmlAT.m_Str);
    SfmlAT.Timing();

    std::string StrHelper = "";

    int k = 0;

    while (window.isOpen())
    {
        window.setFramerateLimit(20);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (k < SfmlAT.m_Str.length())
        {
            StrHelper += SfmlAT.m_Str[k];
            TEXT.setString(StrHelper);
            window.draw(TEXT);
            SfmlAT.Sleep();
            window.display();
            window.clear(sf::Color::Black);
        }

        k++;
    }
    
    
    for (int i = 0; i < str.length(); i++)
    {
        std::cout << AT.m_Str[i];
        AT.Sleep();
    }
}

