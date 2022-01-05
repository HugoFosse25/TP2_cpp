//
//  main.cpp
//  TP2-Fonction décodage trames GPS
//
//  Created by Thomas Marchi on 16/12/2021.
//

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

string decodageTrameNMEA(){
    
}

int main(int argc, const char * argv[]) {
    
    string tramGGA[15];
    tramGGA[0]="";
    tramGGA[1]="";
    tramGGA[2]="";
    tramGGA[3]="";
    tramGGA[4]="";
    tramGGA[5]="";
    tramGGA[6]="";
    tramGGA[7]="";
    tramGGA[8]="";
    tramGGA[9]="";
    tramGGA[10]="";
    tramGGA[11]="";
    tramGGA[12]="";
    tramGGA[13]="";
    
    istringstream NMEA ("$GPGGA,084548,5054.1420,N,00160.0467,E,1,08,0.9,545.4,M,46.9,*42");//metrre le chemin du port série pour récupérer la trame.
           
           string echantillon;
           
           int i = 0;
           
           while (std::getline(NMEA,echantillon,',')){
               
               //cout << "Donnee n°"<< i+1 << " : " << echantillon << '\n' << endl;
               tramGGA[i] = echantillon;
               cout << tramGGA[i]<<endl;
               i++;
           }
}


