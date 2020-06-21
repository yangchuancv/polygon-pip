#ifndef WEATHER_TO_POWER_POLYGON_HPP
#define WEATHER_TO_POWER_POLYGON_HPP

#include <array>
#include <vector>
#include <tuple>


const double DELTA = 0.0001;


class Vertex {
public:
    double coordX;  // Horizontal coordinate
    double coordY;  // Vertical coordinate
};


class Edge {
private:
    double coordXStart;         // Horizontal coordinates of starting vertex
    double coordYStart;         // Vertical coordinates of starting vertex
    double coordXEnd;           // Horizontal coordinates of ending vertex
    double coordYEnd;           // Vertical coordinates of ending vertex
    double singular;            // If true, edge is either horizontal or vertical line
    double singularByX;         // If singular and true, edge is horizontal line, vertical otherwise
    double linearCoefficient;   // If non-singular, linear coefficient of the line defining edge
    double absoluteCoefficient; // If non-singular, absolute coefficient of the line defining edge
public:
    Edge(Vertex start, Vertex end);
    Edge(std::tuple<double, double> start, std::tuple<double, double> end);
    bool RayIntersect(double linearCoefficient, double absoluteCoefficient, double x, double y) const;
    bool OnLine(double x, double y) const;
    std::tuple<Vertex, Vertex> Vertices() const;
};


class Polygon {
private:
    std::array<double, 4> boundaryBox;
    std::vector<Edge> edges;
public:
    Polygon(std::vector<std::tuple<double, double>> vertices);
    bool PipRayCastingAlgorithm(double x, double y) const;
    const std::vector<Edge>& Edges() const;
};


#endif //WEATHER_TO_POWER_POLYGON_HPP