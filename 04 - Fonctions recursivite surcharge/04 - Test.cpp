#include <cstdlib>
#include <iostream>

using namespace std;

bool estBissextile(int annee){
    if (!(annee % 400)){
        return true;
        }else {
            return false;
        }
    }
void afficherAnnee(bool estBissextile){
    if (estBissextile){
        cout << "L'annee est bissextile."<<endl;

        }else{
            cout << "L'annee n'est pas bissextile."<<endl;
            }
    }

int main(){
    afficherAnnee(estBissextile(1900));
    afficherAnnee(estBissextile(2000));
    afficherAnnee(estBissextile(2010));
    afficherAnnee(estBissextile(2020));
    }