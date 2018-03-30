//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    int attack,mHp,hp,y;
    int maxHit,minHit;
    do{
    
        y = (rand() & (maxHit - minHit + 1 )) + minHit;

        cout << "choose an attack: "<< endl;
        cout << "1) Punch"<<endl;
        cout << "2) kick"<<endl ;
        cout << "3) Mega Blast" << endl;
        cin >> attack;

        while ( attack < 1 || attack > 3){
            cout << "try again" << endl;
            cout << " repeat choose an attack: "<< endl;
            cout << "1) Punch"<<endl;
            cout << "2) kick"<<endl ;
            cout << "3) Mega Blast" << endl;
            cin >> attack;          
        }

        if (attack == 1){
            attack = 5;
            mHp = mHp - attack;     
            cout << "the attack was a punch leaving the monster with "<< mHp << " of HP " << endl;
        }else if (attack == 2){
            attack = 10;
            mHp = mHp - attack;
            cout << "the attack was a kick leaving the monster with "<< mHp << " of HP " << endl;
        }else if (attack == 3){
            attack = 20;
            mHp = mHp - attack;
            cout << "the attack was a powerful mega blast leaving the monster with "<< mHp << " of HP " << endl;
        }

        if (y >= 30){ 
            hp = hp - y; 
            cout << "The monster attacks removing " << y << " of your health points which is a critical hit! and now you have "<< hp << " HP" << endl;
        }else{
            hp = hp - y;
            cout << "The monster attacks removing " << y << " of your health points and now you have "<< hp << " HP" << endl;
        }    

        //Save the remaining hp and loop the attack
        cout << hp << endl;
        if (mHp <= 0 ){   
            cout<< " monster reaches to 0" << endl;

        }else if (hp <= 0 ){
            cout<< " player reaches to 0" << endl;

        }

    }while ( hp < 0 || mHp < 0 );

    cout << "end of attacks" << endl;
    return 0;
}