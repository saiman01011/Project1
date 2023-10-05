#include <SFML/Graphics.hpp>
const int weignt = 783;
const int heignt = 783;
bool clik = false;
int nom = -1;//номер фигуры 
int positeun(int a) {
    int s = a / 97;
    return s * 97 + 50;
}
class figyra {
public:
    int x = 0, y = 0, nam = 0;
    bool caler_f = true;//если фигура белая то истена 
    sf::Sprite asd;//изображение;
    void start(int x, int y, bool caler_f, sf::Sprite zxc) {

        asd = zxc;
        asd.move(20 + (97 * x), (97 * y));
        this->x = x;
        this->y = y;
        this->caler_f = caler_f;
    }
    figyra() {

    }
};

int main()
{
    using namespace sf;
    RenderWindow window(sf::VideoMode(weignt, heignt), "geme", Style::None);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);


    Image mapImage;
    Texture mapTexture;
    Sprite map, spri_pe;
    Event event;
    figyra figyr[32];


    mapImage.loadFromFile("map1.png");
    mapImage.createMaskFromColor(Color(78, 144, 79));
    mapTexture.loadFromImage(mapImage);
    map.setTexture(mapTexture);
    spri_pe.setTexture(mapTexture);


    for (int i = 0; i < 16; i++) {//пешки
        if (i < 8) {
            spri_pe.setTextureRect(IntRect(0, 784, 57, 97));
            figyr[i].start(i, 6, false, spri_pe);
        }
        else {
            spri_pe.setTextureRect(IntRect(0, 878, 57, 97));
            figyr[i].start((i - 8), 1, true, spri_pe);
        }
    }
    for (int i = 1, j = 7; i < 4; i++, j--) {
        spri_pe.setTextureRect(IntRect(57 * i, 784, 57, 97));
        figyr[15 + i].start(i - 1, 7, true, spri_pe);
        spri_pe.setTextureRect(IntRect(57 * i, 784 + 97, 57, 97));
        figyr[18 + i].start(i - 1, 0, false, spri_pe);
        spri_pe.setTextureRect(IntRect(57 * i, 784, 57, 97));
        figyr[21 + i].start(7 - i + 1, 7, true, spri_pe);
        spri_pe.setTextureRect(IntRect(57 * i, 784 + 97, 57, 97));
        figyr[24 + i].start(j, 0, false, spri_pe);

    }
    spri_pe.setTextureRect(IntRect(57 * 4, 784, 54, 97));
    figyr[28].start(3, 7, true, spri_pe);
    spri_pe.setTextureRect(IntRect(57 * 5, 784, 50, 97));
    figyr[29].start(4, 7, true, spri_pe);


    spri_pe.setTextureRect(IntRect(57 * 4, 784 + 97, 54, 97));
    figyr[30].start(4, 0, false, spri_pe);
    spri_pe.setTextureRect(IntRect(57 * 5, 784 + 97, 50, 97));
    figyr[31].start(3, 0, false, spri_pe);

    Vector2i mou_po = Mouse::getPosition() - window.getPosition();
    Vector2i maus_s;

    maus_s.x = 20;
    maus_s.y = 572;
    map.setTextureRect(IntRect(0, 0, 783, 783));
    while (window.isOpen())
    {
        window.clear();

        window.draw(map);
        for (int i = 0; i < 32; i++) {
            window.draw(figyr[i].asd);
        }

        window.display();
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed) {
                if (event.key.code == Mouse::Left) {
                    mou_po = Mouse::getPosition() - window.getPosition();
                    for (int i = 0; i < 32; i++) {
                        if ((figyr[i].x == mou_po.x / 97) && (figyr[i].y == mou_po.y / 97)) {
                            clik = true;
                            nom = i;
                        }
                    }
                }
            }
            if (event.type == Event::MouseButtonReleased) {
                if (event.key.code == Mouse::Left) {
                    clik = false;
                }
            }
        }
        if (clik) {
            mou_po = Mouse::getPosition() - window.getPosition();
            figyr[nom].asd.setOrigin(28, 58);
            figyr[nom].asd.setPosition(mou_po.x, mou_po.y);
            figyr[nom].x = mou_po.x / 97;
            figyr[nom].y = mou_po.y / 97;
            maus_s = mou_po;
        }
        else {
            figyr[nom].asd.setPosition(positeun(maus_s.x), positeun(maus_s.y));
        }

    }
    return 0;
}