#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> getMatrixInput(int size) {
    vector<vector<int>> matrix(size, vector<int>(size));
    int value = 1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = value++;
        }
    }
    return matrix;
}

vector<vector<int>> sliceMatrix(const vector<vector<int>>& matrix, int size) {
    vector<vector<int>> slicedMatrix;
    for (int i = 1; i < size - 1; ++i) {
        vector<int> row;
        for (int j = 1; j < size - 1; ++j) {
            row.push_back(matrix[i][j]);
        }
        slicedMatrix.push_back(row);
    }
    return slicedMatrix;
}

void drawMatrix(const vector<vector<int>>& matrix, sf::RenderWindow& window, float xOffset, float yOffset) {
    int cellSize = 50;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Error loading font" << endl;
        return;
    }
    
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(xOffset + j * cellSize, yOffset + i * cellSize);
            cell.setFillColor(sf::Color::Blue);
            cell.setOutlineThickness(1);
            cell.setOutlineColor(sf::Color::White);
            window.draw(cell);

            sf::Text text;
            text.setFont(font);
            text.setString(to_string(matrix[i][j]));
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::White);
            text.setPosition(xOffset + j * cellSize + 15, yOffset + i * cellSize + 10);
            window.draw(text);
        }
    }
}

int main() {
    int size;
    cout << "Enter matrix size: ";
    cin >> size;

    vector<vector<int>> matrix = getMatrixInput(size);
    vector<vector<int>> slicedMatrix = sliceMatrix(matrix, size);

    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Matrix Slicing");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        drawMatrix(matrix, window, 50, 50);
        drawMatrix(slicedMatrix, window, 400, 50);

        window.display();
    }

    return 0;
}
