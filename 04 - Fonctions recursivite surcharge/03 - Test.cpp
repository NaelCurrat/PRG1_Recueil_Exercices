#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

double volumePyramide(double longeur, double largeur, double hauteur){
    double volumePy = (longeur * largeur * hauteur)/3;
    return volumePy;
}

void afficherVolume(double volumePyramide){
    cout << "Le volume de la pyramide est de : " << volumePyramide <<endl;
}

int main(){
    double longeurPy1 = 10;
    double largeurPy1 = 3.5;
    double hauteurPy1 = 12;
    afficherVolume(volumePyramide(longeurPy1, largeurPy1, hauteurPy1));
    double longeurPy2 = 3.6;
    double largeurPy2 = 2.4;
    double hauteurPy2 = 2.7;
    afficherVolume(volumePyramide(longeurPy2, largeurPy2, hauteurPy2));
}