#include <iostream>
#include <stdio.h>        
#include <stdlib.h>
#include <string.h>
#include <fstream>                                    
#include <math.h>


using namespace std;

const int MADBEAR = 1;                   // Nguyễn Phước Nguyên Phúc - 2053342
const int BANDIT = 2;
const int LordLupin = 3;
const int Elf = 4;
const int Troll = 5;       
const int Shaman = 6;
const int Vajsh = 7;
const int Excalibur = 8;
const int Mythril = 9;
const int Excalipoor = 10;
const int MushMario = 11;
const int MushFib = 12;
const int MushGhost = 13;
const int MushKnight = 14;
const int Remedy = 15;
const int PhoenixDown = 16;
const int Merlin = 17;
const int Nina = 18;
const int Abyss = 19;
const int TimeGate = 20;
const int Guinevere = 21;
const int Lightwing = 22;
const int Odin = 23;
const int DragonSword = 24;
const int Bowser = 99;
const int BowserSur = 0;
const int EVENT_SIZE = 100;
const int MAX_CHARACTER_EACH_LINE = 250;

struct knight
{
    int HP;
    int DF;
    int level;
    int remedy;
    int gold;
    int phoenixdown;
};

// read data from input file to corresponding variables
// return 1 if successfully done, otherwise return 0

int Fibonacci(int hp) {        // cho case nấm fibonaci
    int i = 1,j=1,F=0;
    do {
        F = i + j;
        i = j;
        j = F;     
    } while (F < hp);
    hp = hp + i;    // lúc này F sẽ lớn hơn hoặc bằng HP, j=F và i là cận dưới
    return hp;
}

int Friendlynum(int hp, int goldd) {     // cho case friendlynumber Nina
    int sumhp = 0; int sumgoldd = 0;
    for (int i = 1; i <= (hp / 2); i++) {
        if (hp % i == 0) {
            sumhp = sumhp + i;
        }
    }
    for (int j = 1; j <= (goldd / 2); j++) {
        if (goldd % j == 0) {
            sumgoldd = sumgoldd + j;
        }
    }

    if ((sumhp/hp) == (sumgoldd/goldd)) {
        return 1;
    }
    else {
        return 0;
    }

}

int startJourney(knight theKnight, int nEvent, int* arrEvent) {
    int s = 0, Arthur = 0, Paladin = 0, DragonKnight = 0, Lancelot = 0, NormalKnight = 0;
    for (int j = 2; j < theKnight.HP; j++) {
        if (theKnight.HP % j == 0) {
            s = s + 1;
        }
    }
    if (s == 0) {                                // check xem có phải hiệp sĩ Paladin ?
        Paladin = 1;
    }

    if (theKnight.HP == 999) {                  // check Arthur
        Arthur = 1;
    }
    else if (theKnight.HP == 888) {                  // check lancelot
        if (theKnight.level % 2 == 1) {                                      
            Lancelot = 2;
        }
        else {
            Lancelot = 1;
        }
    }
    else if (theKnight.HP != 999 && theKnight.HP != 888) {    // nếu máu ko phải 888 or 999 
        float z;
        int Dragon;
        for (int a = 1; a < 500; a++) {
            for (int b = 1; b < 500; b++) {
                z = a * a + b * b;
                if (sqrt(z) == (int)sqrt(z)) {
                    Dragon = a + b + sqrt(z);               // check dragon knight
                    if (theKnight.HP == Dragon) {
                        DragonKnight = 1;
                      
                    }
                }
            }
        }
        if (DragonKnight != 1 && Paladin == 0) {
            NormalKnight = 1;                             // nếu ko phải thì là normal knight
        }
    }
    int a, b, hp, goldd, baselevel, levelO, damage, CountShaman=0, CountVajsh=0, UsingExcalibur=0, UsingExcalipoor=0, EquipMythril=0, OdinHelp=0, countOdin=0, countMythril=0,UsingDragonSword=0, CountLightwing =0, FirstOdin=0,Timegateth=-1,Mythrilrest=0, Guinevereescape=0;  // các biến sự kiện
    int MaxHP = theKnight.HP;    // max HP ban đầu
    double baseDamage;      //basedamage của quái         
    int sum = 0;         // sum cho tổng mật mã mới >15 hay ko
    string code;           // string để giải mật mã Abyss
    int k = 1;              // biến để thay đổi sự kiện nếu gặp công chúa
    for (int i = 0; i < nEvent; i++)
    {     
        int theEvent = arrEvent[i];
        
        //cout << theEvent << endl;
        switch (theEvent)
        {
        case MADBEAR:     
            code += "1";
            b = (i + 1) % 10;
            levelO = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
            if (Arthur == 1 || Lancelot == 2 || Paladin == 1 || DragonKnight == 2 || UsingExcalibur ==1 || OdinHelp ==1) {            // Auto win
                theKnight.DF = theKnight.DF + 1;
                theKnight.level = theKnight.level + 1;
                theKnight.gold = theKnight.gold + 10;
            }
            else {
                if (UsingExcalipoor == 1) {                           // dùng gươm shopee
                    baseDamage = 1;
                    damage = baseDamage * levelO * 10;
                    if (EquipMythril == 1) {                           // có giáp thì cản damage
                    }
                    else if (damage > theKnight.DF) {
                        theKnight.HP = theKnight.HP + theKnight.DF - damage;
                    }
                }
                else if (theKnight.level > levelO) {                    // level hơn
                    theKnight.DF = theKnight.DF + 1;
                    theKnight.level = theKnight.level + 1;
                    theKnight.gold = theKnight.gold + 10;
                }
                else if (theKnight.level < levelO) {                   // level thua 
                    baseDamage = 1;
                    damage = baseDamage * levelO * 10;
                    if (EquipMythril == 1) {
                    }
                    else if (damage > theKnight.DF) {
                        theKnight.HP = theKnight.HP + theKnight.DF - damage;
                    }
                }
                else {            
                }
            }
            break;
        case BANDIT:     //done
            code += "2";
            b = (i + 1) % 10;
            levelO = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
            if (Arthur == 1 || Lancelot == 2 || Paladin == 1 || DragonKnight == 2 || UsingExcalibur == 1 || OdinHelp == 1) {
                theKnight.DF = theKnight.DF + 1;
                theKnight.level = theKnight.level + 1;
                theKnight.gold = theKnight.gold + 20;
            }
            else {
                if (UsingExcalipoor == 1) {
                    baseDamage = 2.5;
                    damage = baseDamage * levelO * 10;
                    if (EquipMythril == 1) {
                    }
                    else if (damage > theKnight.DF) {
                        theKnight.HP = theKnight.HP + theKnight.DF - damage;
                    }
                }
                else if (theKnight.level > levelO) {
                    theKnight.DF = theKnight.DF + 1; 
                    theKnight.level = theKnight.level + 1;
                    theKnight.gold = theKnight.gold + 20;
                }
                else if (theKnight.level < levelO) {
                    baseDamage = 2.5;
                    damage = baseDamage * levelO * 10;
                    if (EquipMythril == 1) {
                    }
                    else if (damage > theKnight.DF) {
                        theKnight.HP = theKnight.HP + theKnight.DF - damage;
                    }
                }
                else {
                }
            }
            break;
        case LordLupin:     //done
            code += "3";
            b = (i + 1) % 10;
            levelO = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
            if (Arthur == 1 || Lancelot == 2 || Paladin == 1 || DragonKnight == 2 || UsingExcalibur == 1 || OdinHelp == 1) {
                theKnight.DF = theKnight.DF + 1;
                theKnight.level = theKnight.level + 1;
                theKnight.gold = theKnight.gold + 30;
            }
            else {     
                if (UsingExcalipoor == 1) {
                    baseDamage = 5.5;
                    damage = baseDamage * levelO * 10;
                    if (EquipMythril == 1) {
                    }
                    else if (damage > theKnight.DF) {
                        theKnight.HP = theKnight.HP + theKnight.DF - damage;
                    }
                }
                else if (theKnight.level > levelO) {
                    theKnight.DF = theKnight.DF + 1;
                    theKnight.level = theKnight.level + 1;
                    theKnight.gold = theKnight.gold + 30;
                }
                else if (theKnight.level < levelO) {
                    baseDamage = 5.5;
                    damage = baseDamage * levelO * 10;
                    if (EquipMythril == 1) {
                    }
                    else if (damage > theKnight.DF) {
                        theKnight.HP = theKnight.HP + theKnight.DF - damage;
                    }                  
                }
                else {
                }
            }
            break;
        case Elf:     //done
            code += "4";
            b = (i+1) % 10;
            levelO = (i+1) > 6 ? (b > 5 ? b : 5) : b;
            if (Arthur == 1 || Lancelot == 2 || Paladin == 1 || DragonKnight == 2 || UsingExcalibur == 1 || OdinHelp == 1) {
                theKnight.DF = theKnight.DF + 1;
                theKnight.level = theKnight.level + 1;
                theKnight.gold = theKnight.gold + 40;
            }
            else {
                if (UsingExcalipoor == 1) {
                    baseDamage = 7.5;
                    damage = baseDamage * levelO * 10;
                    if (EquipMythril == 1) {
                    }
                    else if (damage > theKnight.DF) {
                        theKnight.HP = theKnight.HP + theKnight.DF - damage;
                    }
                }
                else if (theKnight.level > levelO) {
                    theKnight.DF = theKnight.DF + 1;
                    theKnight.level = theKnight.level + 1;
                    theKnight.gold = theKnight.gold + 40;
                }
                else if (theKnight.level < levelO) {
                    baseDamage = 7.5;
                    damage = baseDamage * levelO * 10;
                    if (EquipMythril == 1) {
                    }
                    else if (damage > theKnight.DF) {
                        theKnight.HP = theKnight.HP + theKnight.DF - damage;
                    }
                }
                else {
                }
            }
            break;
        case Troll:     //done
            code += "5";
            b = (i + 1) % 10;
            levelO = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
            if (Arthur == 1 || Lancelot == 2 || Paladin == 1 || DragonKnight == 2 || UsingExcalibur == 1 || OdinHelp == 1) {
                theKnight.DF = theKnight.DF + 1;
                theKnight.level = theKnight.level + 1;
                theKnight.gold = theKnight.gold + 50;
            }
            else {
                if (UsingExcalipoor == 1) {
                    baseDamage = 9.5;
                    damage = baseDamage * levelO * 10;
                    if (EquipMythril == 1) {
                    }
                    else if (damage > theKnight.DF) {
                        theKnight.HP = theKnight.HP + theKnight.DF - damage;
                    }
                }
                else if (theKnight.level > levelO) {
                    theKnight.DF = theKnight.DF + 1;
                    theKnight.level = theKnight.level + 1;
                    theKnight.gold = theKnight.gold + 50;
                }
                else if (theKnight.level < levelO) {
                    baseDamage = 9.5;
                    damage = baseDamage * levelO * 10;
                    if (EquipMythril == 1) {
                    }
                    else if (damage > theKnight.DF) {
                        theKnight.HP = theKnight.HP + theKnight.DF - damage;
                    }
                }
                else if(theKnight.level==levelO) {
                }
            }
            break;
        case Shaman: // done
            code += "6";
            b = (i + 1) % 10;
            levelO = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
            if (Arthur == 1 || Lancelot == 2 || Paladin == 1 || DragonKnight == 2 || OdinHelp==1) {         //auto win
                theKnight.DF = theKnight.DF + 2;
                theKnight.level = theKnight.level + 2;
            }
            else if (CountShaman > 1 && CountShaman < 5) {
            }
            else if (CountVajsh > 1 && CountVajsh < 5) {
            }
            else {
                if (UsingExcalipoor == 1) {
                    CountShaman = 1;
                    if (theKnight.HP >= 5) {
                        theKnight.HP = theKnight.HP / 5;
                    }
                    else if (theKnight.HP < 5) {
                        theKnight.HP = 1;
                    }
                }
                else if (theKnight.level > levelO) {
                    theKnight.DF = theKnight.DF + 2;
                    theKnight.level = theKnight.level + 2;
                }
                else if (theKnight.level < levelO) {
                    CountShaman = 1;
                    if (theKnight.HP >= 5) {
                        theKnight.HP = theKnight.HP / 5;
                    }
                    else if (theKnight.HP < 5) {
                        theKnight.HP = 1;
                    }
                }
                else {
                }
            }
            break;
        case Vajsh: // done
            code += "7";
            b = (i + 1) % 10;
            levelO = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
            if (Arthur == 1 || Lancelot == 2 || Paladin == 1 || DragonKnight == 2||OdinHelp ==1) {
                theKnight.DF = theKnight.DF + 2;
                theKnight.level = theKnight.level + 2;
            }
            else if (CountShaman > 1 && CountShaman < 5) {
            }
            else if (CountVajsh > 1 && CountVajsh < 5) {
            }
            else {
                if (UsingExcalipoor == 1) {
                    baselevel = theKnight.level;  // gán level hiên tại vào baselevel
                    CountVajsh = 1;
                    theKnight.level = 1;
                }
                else if (theKnight.level > levelO) {
                    theKnight.DF = theKnight.DF + 2;
                    theKnight.level = theKnight.level + 2;
                }
                else if (theKnight.level < levelO) {
                    baselevel = theKnight.level;
                    CountVajsh = 1;
                    theKnight.level = 1;
                }
                else {
                }
            }
            break;
        case Excalibur: //done
            code += "8";
            if(DragonKnight == 2){                 // ko thèm nhặt
            }
            else {
                UsingExcalibur = 1;
                UsingExcalipoor = 0;         // nhặt 
                
            }
            break;
        case Mythril:  //done
            code += "9";
            if (Mythrilrest == 1 || Mythrilrest == 2) { //2 sự kiện nghỉ ngơi ko mặc giáp nên bỏ qua
            }
            else {
                if (EquipMythril == 1) {   // đang mặc nên bỏ qua
                }
                else if (EquipMythril == 0) {
                    EquipMythril = 1;
                    countMythril = 1;
                }
            }
            break;
        case Excalipoor://done
            code += "10";
            if (theKnight.level >= 5) {              // ko bị lừa hàng shopee
            }
            else if (Arthur == 1 || Paladin == 1 || DragonKnight == 1 || DragonKnight == 2 || Lancelot == 2 || OdinHelp==1) {         // ko bị lừa nốt
            }
            else {
                UsingExcalipoor = 1;
                UsingExcalibur = 0;           //   bị lừa,    bỏ gươm xịn và gươm rồng
            }
            break;
        case MushMario:    //done
            code += "11";
            theKnight.HP = theKnight.HP + 50;       // cộng 50 máu
            break;
        case MushFib: //done
            code += "12";
            hp = theKnight.HP;                     // cộng vào số Fibo cận dưới
            theKnight.HP = Fibonacci(hp);
            break;
        case MushGhost:    //done
            code += "13";
            if (Paladin == 1 || DragonKnight == 2 || OdinHelp==1) {     // ko đạp nấm 
            }
            else {
                if (theKnight.HP >= 51) {                    // đạp nấm và máu >50
                    theKnight.HP = theKnight.HP - 50;
                }
                else {                                              
                    theKnight.HP = 1;              
                }

                if (theKnight.DF >= 6) {
                    theKnight.DF = theKnight.DF - 5;         // đạp nấm và level >5
                }
                else {
                    theKnight.DF = 1;
                }
            }
            break;
        case MushKnight: //done
            code += "14";                    // MaxHP + 50 // máu lên maxHP
            MaxHP = MaxHP + 50;
            theKnight.HP = MaxHP;
            break;
        case Remedy: //done
            code += "16";                            
            theKnight.remedy = theKnight.remedy + 1;
            break;
        case PhoenixDown: //done
            code += "16";
            theKnight.phoenixdown = theKnight.phoenixdown + 1;
            break;
        case Merlin: //done
            code += "17";      
            if (CountShaman > 0 && CountShaman < 5) {               // giải hiệu ứng    
                CountShaman = 0;
                theKnight.HP *= 5;
            }
            else if (CountVajsh > 0 && CountVajsh < 5) {
                CountVajsh = 0;
                theKnight.level = baselevel;
            }
            theKnight.level = theKnight.level + 1;             // level +1;
            theKnight.HP = MaxHP;
            break;
        case Nina: //done
            code += "18";
            hp = theKnight.HP;
            goldd = theKnight.gold;
            if (Friendlynum(hp,goldd) == 1) {
                if (CountShaman > 0 && CountShaman < 5) {                                 // nếu Hp gold là cặp số bạn
                    CountShaman = 0;
                    theKnight.HP = MaxHP;
                }
                else if (CountVajsh > 0 && CountVajsh < 5) {                  // giải hiệu ứng & cộng máu free
                    CountVajsh = 0;
                    theKnight.level = baselevel;
                    theKnight.HP = MaxHP;
                }
                else {
                    theKnight.HP = MaxHP;
                }
            }
            else {
                if (theKnight.gold >= 50) {
                    if (CountShaman > 0 && CountShaman < 5) {             // có 50 tiền mua sắm  // giải hiệu ứng //  cộng máu                        
                        theKnight.gold -= 50;
                        CountShaman = 0;
                        theKnight.HP *= 5;
                    }
                    else if (CountVajsh > 0 && CountVajsh < 5) {
                        theKnight.gold -= 50;
                        CountVajsh = 0;
                        theKnight.level = baselevel;
                    }
                    if (theKnight.gold <= (MaxHP - theKnight.HP)) {     // cộng máu nến chưa đến maxHP
                        theKnight.HP += theKnight.gold;
                        theKnight.gold = 0;
                    }
                    else {
                        theKnight.gold -= (MaxHP - theKnight.HP);      // đến ngưỡng max HP
                        theKnight.HP = MaxHP;
                    }
                }
                else {      // ko đủ tiền mà cũng ko phải số bạn
                }
            }
            break;
        case Abyss:
            if (DragonKnight == 2) {               // dragonknight nhảy
            }
            if (theKnight.level >= 7) {          // level hơn hoặc bằng 7 nhảy
                code += "19";
            }
            else if (theKnight.gold >= 50) {      // có 50 tiền
                theKnight.gold -= 50;
                code += "19";
            }
            else {                              // giải mật mã
                #pragma warning (disable : 4996)         // turn off the Warning cho hàm itoa    // em xài VS thì nó cảnh báo gì đấy nhưng ko phải lỗi ạ            
                char hp[3];  // create char for knight's infor          // If the knight have to solve the code , now we have string "code" first contain all the events have been passed.               
                char df[2];                                                    // now adding the infor of the knight
                char level[2];
                char remedys[2];
                char golds[3];
                char phoenixdowns[2];
                itoa(theKnight.HP, hp, 10);  //convert infor of the knight into char type
                itoa(theKnight.DF, df, 10);
                itoa(theKnight.level, level, 10);
                itoa(theKnight.remedy, remedys, 10);
                itoa(theKnight.gold, golds, 10);
                itoa(theKnight.phoenixdown, phoenixdowns, 10);
                code += hp;  //add knight's infor into string code
                code += df;
                code += level; 
                code += remedys;
                code += golds;
                code += phoenixdowns;
                char newe[500];  // convert string code into char type "newe" , the size of newe is 500 
                for (int j = 0; j < code.size(); j++) {
                    newe[j] = code[j];
                }
                sum = 0;      // tổng của chuỗi mới
                string solvecode; // chuỗi mới sau khi giải xong sẽ dc cho vào đây
                char find9 = '9';           // tìm số 9 trong chuỗi đầu
                int r = 0;
                int count = 0;             // bien dem
                while (newe[r] != '\0') {
                    if (newe[r] == find9)
                        count++;               // đếm số lần xuất hiện của số 9, nếu 1 lần thì thêm vào chuỗi mới
                    r++;
                }
                if (count == 1) {
                    sum += 9;
                    solvecode += find9;
                }
                char find8 = '8';
                r = 0;
                count = 0;             // bien dem
                while (newe[r] != '\0') {
                    if (newe[r] == find8)
                        count++;
                    r++;
                }
                if (count == 1) {
                    sum += 8;
                    solvecode += find8;
                }
                char find7 = '7';
                r = 0;
                count = 0;             // bien dem
                while (newe[r] != '\0') {
                    if (newe[r] == find7)
                        count++;
                    r++;
                }
                if (count == 1) {
                    sum += 7;
                    solvecode += find7;
                }
                char find6 = '6';
                r = 0;
                count = 0;             // bien dem
                while (newe[r] != '\0') {
                    if (newe[r] == find6)
                        count++;
                    r++;
                }
                if (count == 1) {
                    sum += 6;
                    solvecode += find6;
                }
                char find5 = '5';
                r = 0;
                count = 0;            
                while (newe[r] != '\0') {
                    if (newe[r] == find5)
                        count++;
                    r++;
                }
                if (count == 1) {
                    sum += 5;
                    solvecode += find5;
                }
                char find4 = '4';
                r = 0;
                count = 0;             
                while (newe[r] != '\0') {
                    if (newe[r] == find4)
                        count++;
                    r++;
                }
                if (count == 1) {
                    sum += 4;
                    solvecode += find4;
                }
                char find3 = '3';
                r = 0;
                count = 0;            
                while (newe[r] != '\0') {
                    if (newe[r] == find3)
                        count++;
                    r++;
                }
                if (count == 1) {
                    sum += 3;
                    solvecode += find3;
                }
                char find2 = '2';
                r = 0;
                count = 0;             
                while (newe[r] != '\0') {
                    if (newe[r] == find2)
                        count++;
                    r++;
                }
                if (count == 1) {
                    sum += 2;
                    solvecode += find2;
                }
                char find1 = '1';
                r = 0;
                count = 0;             
                while (newe[r] != '\0') {
                    if (newe[r] == find1)
                        count++;
                    r++;
                }
                if (count == 1) {
                    sum += 1;
                    solvecode += find1;
                }
                char find0 = '0';
                r = 0;
                count = 0;             
                while (newe[r] != '\0') {
                    if (newe[r] == find0)
                        count++;
                    r++;
                }
                if (count == 1) {
                    sum += 0;
                    solvecode += find0;
                }              // chúng ta có chuỗi mới dc giải ở trong string "solvecode"                             
                if (sum > 15) {
                    code += "19"; //pass
                }
                else {
                    theKnight.HP -= 9999; //die       nhưng vẫn có khả năng hồi sinh
                }
            }
            break;
        case TimeGate: //done
            code += "20";
            Timegateth = i;
            break;
        case Guinevere:
            code += "21";
            Guinevereescape = 1;
            break;
        case Lightwing: //done
            code += "22";
            if (i >= (nEvent - 3)) {
                return theKnight.HP + theKnight.DF + theKnight.level + theKnight.remedy + theKnight.gold + theKnight.phoenixdown;
            }
            else if (arrEvent[i + 1] == 21 || arrEvent[i+2]==21 || arrEvent[i+3]==21) {     // trong 3 case tiếp theo có case gặp công chúa
                return theKnight.HP + theKnight.DF + theKnight.level + theKnight.remedy + theKnight.gold + theKnight.phoenixdown;
            }
            else if (arrEvent[i + 1] == 0 || arrEvent[i + 2] == 0 || arrEvent[i + 3] == 0) {      // 3 case tiếp theo có case Bowser đầu hàng
                return theKnight.HP + theKnight.DF + theKnight.level + theKnight.remedy + theKnight.gold + theKnight.phoenixdown;
            }
            else if (CountLightwing==0) {
                CountLightwing = 1;
            }         
            break;
        case Odin: //done
            code += "23";
            if (FirstOdin == 0) {
                OdinHelp = 1;
                countOdin = 1;
                FirstOdin = 1;
            }
            break;
        case DragonSword: //done
            code += "24";
            if (DragonKnight == 1) {      // chỉ drsgonknight mới nhặt thanh gươm này
                DragonKnight =2;
            }
            else {                // các case còn lại đều bỏ qua
            }
            break;
        case Bowser: //done
            code += "99";
            if (Arthur == 1  && theKnight.level >= 8) {
                theKnight.level = 10;
            }
            else if (Paladin == 1 && theKnight.level >= 8) {
                theKnight.level == 10;
            }
            else if (Lancelot == 1 || Lancelot == 2) {
                theKnight.level == 10;
            }
            else if (NormalKnight == 1 && theKnight.level == 10) {
            }
            else if (DragonKnight == 1 && theKnight.level == 10) {
            }
            else if (DragonKnight == 2) {
                theKnight.level = 10;
            }
            else if (OdinHelp == 1) {
                theKnight.level = 10;
            }
            else {
                return -1;
            }
            break;
        case BowserSur:       // nếu gặp case Bowser ff
            return theKnight.HP + theKnight.DF + theKnight.level + theKnight.remedy + theKnight.gold + theKnight.phoenixdown;
        }

        if (MaxHP > 999) {
            MaxHP = 999;
        }
        if (theKnight.HP > 999) {
            theKnight.HP = 999;
        }
        if (theKnight.HP >= MaxHP) {
            theKnight.HP = MaxHP;
        }
        if (theKnight.DF > 20) {
            theKnight.DF = 20;
        }
        if (theKnight.level > 10) {
            theKnight.level = 10;
        }
        if (theKnight.gold > 500) {
            theKnight.gold = 500;
        }
        if (theKnight.remedy > 99) {
            theKnight.remedy = 99;
        }
        if (theKnight.phoenixdown > 99) {
            theKnight.phoenixdown = 99;
        }

        if ((theKnight.level % 2 != 0) && Lancelot == 1) { // chuyển dạng xịn nếu level lẻ
            Lancelot = 2;
        }
        if (Lancelot == 2 && (theKnight.level % 2 == 0)) {    // Lancelot chuyển dạng thường nếu level chẵn
            Lancelot = 1;
        }

        if (theKnight.HP <= 0 && theKnight.phoenixdown > 0) {   // có phoenixdown dc hồi sinh
            if (Timegateth != -1) {         // đã đi qua time gate
                theKnight.HP = MaxHP;
                theKnight.phoenixdown = theKnight.phoenixdown - 1;
                i = Timegateth;
            }
            else {
                theKnight.HP = MaxHP;
                theKnight.phoenixdown = theKnight.phoenixdown - 1;
            }
        }
        else if(theKnight.HP <= 0 && theKnight.phoenixdown == 0){         // chết mà ko có hồi sinh 
            return -1;
        }

        if (CountShaman > 0 && CountVajsh < 5 && theKnight.remedy >0) {   // giải hiệu ứng
            theKnight.remedy -= 1;
            CountShaman = 0;
        }
        if (CountVajsh > 0 && CountVajsh < 5 && theKnight.remedy>0) {       // giải hiệu ứng
            theKnight.remedy -= 1;
            CountVajsh = 0;
        }

        if (CountShaman == 1 || CountShaman == 2 || CountShaman == 3||CountShaman==4) {
            CountShaman = CountShaman + 1;
            UsingExcalibur = 0;                     // biến cóc ko dùng dc gươm real
        }
        if (CountShaman == 5) {
            CountShaman = 0;
            theKnight.HP *= 5;
        }
        if (CountVajsh == 1 || CountVajsh == 2 || CountVajsh == 3|| CountVajsh==4) {
            CountVajsh = CountVajsh + 1;
            UsingExcalibur = 0;       // biến nhỏ ko dùng dc gươm real
        }
        if (CountVajsh == 5) {
            CountVajsh = 0;
            theKnight.level = baselevel;
        }
        if (countMythril > 0 && countMythril <= 6) {            // count số event mang giáp
            countMythril++;
        }
        if (Mythrilrest == 1) {             // nghỉ 1 event 
            Mythrilrest++;
        }
        if (countMythril == 7) {       // hết thời gian mang giáp
            EquipMythril = 0;
            countMythril = 0;
            Mythrilrest = 1;
        }
        if (Mythrilrest == 2) {     // nghỉ 2 event rồi thì có thể mang giáp lại
            Mythrilrest = 0;
        }
        if (CountLightwing == 1) {    // đếm cánh thần // sự kiện chuyển tới sự kiện thứ 4 
            i = i + 3;
            CountLightwing = 0;
        }
        if (countOdin == 1||countOdin==2||countOdin==3||countOdin==4) {       // đếm Odin
            countOdin++;
        }
        if (countOdin == 5) {       // hết Odin
            OdinHelp = 0;
            countOdin = 0;
        }
        if (Guinevereescape == 1) {           // gặp công chúa
            Guinevereescape = 0;
            nEvent = 2 * i + 1;               // thay đổi lại số lượng sự kiện
            for (k; k <= i; k++) { 
                arrEvent[i + k] = arrEvent[i - k];         // thay đổi những sự kiện sau thanh những sự kiện đã đi qua
            }           
        }
 
    }
    return theKnight.HP + theKnight.DF + theKnight.level + theKnight.remedy + theKnight.gold + theKnight.phoenixdown; // kết thúc - in ra màn hình
}

