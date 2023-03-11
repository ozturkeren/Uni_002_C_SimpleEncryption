// Eren Öztürk METU NCC 140 PA1
#include<stdio.h>
#include<math.h>
int main()
{
    int option/*Taking option*/,secretcode='A',controler/*Controller for secret code/is the input in the right interval*/,volunteer/*Do what I want(Ich wyllan)*/,binaried,changer/*Changing for its duty*/,baseSelect,counttoEight,differentInput=0;
    char secretZero='0',secretOne='0',secretTwo='0',secretThree='0',secretFour='0',secretFive='0',secretSix='0',secretSeven='0';
    //base 2
    char baseTwoBinaryZero='0',baseTwoBinaryOne='0',baseTwoBinaryTwo='0',baseTwoBinaryThree='0',baseTwoBinaryFour='0',baseTwoBinaryFive='0',baseTwoBinarySix='0',baseTwoBinarySeven='0';
    char encryptedZero='0',encryptedOne='0',encryptedTwo='0',encryptedThree='0',encryptedFour='0',encryptedFive='0',encryptedSix='0',encryptedSeven='0';
    char resultedChar;//general
    //base 16
    int firstDecimal,secondDecimal,sumOfBase16Decimals;
    char firstScannedChar,secondScannedChar;
    char baseSixteenBinaryZero,baseSixteenBinaryOne,baseSixteenBinaryTwo,baseSixteenBinaryThree,baseSixteenBinaryFour,baseSixteenBinaryFive,baseSixteenBinarySix,baseSixteenBinarySeven;



    volunteer=secretcode;//Start of being secret code of 'A'
    for(binaried=0,changer=1;volunteer>0;changer*=10,volunteer/=2){//writing secret code in int but in binary
        binaried=binaried+(volunteer%2)*changer;
    }
    secretZero=(binaried%2)==1 ? '1':'0';
    secretOne=(binaried/10)%2==1 ? '1':'0';
    secretTwo=(binaried/100)%2==1 ? '1':'0';
    secretThree=(binaried/1000)%2==1 ? '1':'0';
    secretFour=(binaried/10000)%2==1 ? '1':'0';
    secretFive=(binaried/100000)%2==1 ? '1':'0';
    secretSix=(binaried/1000000)%2==1 ? '1':'0';
    secretSeven=(binaried/10000000)%2==1 ? '1':'0';//secret code is char and in binary
    printf("\nHappy Encryption! ");

    do{
        printf("\n(1) Change the secret code \n(2) Encrypt text  \n(3) Quit \nYou choose: ");
        scanf("%d",&option);//Taking user's option
        switch(option)
        {
            case 1://For changing the secret code
                printf("\nYou have chosen option 1!\n");
                do{
                        printf("\nWhich secret code will you use? ");
                        scanf("\n%c",&secretcode);//taking new secret code it was 'A'
                        printf("\nsecret: %d\n",secretcode);
                        controler=0;
                        if((((secretcode<48)||(secretcode>57))&&((secretcode<65)||(secretcode>90))&&((secretcode<97)||(secretcode>122)))){
                            printf("\n%c is not accepted as a secret code, please enter secret code again (0-9, A-Z, a-z)?",secretcode);
                        }
                }while((((secretcode>=48)&&(secretcode<=57))||((secretcode>=65)&&(secretcode<=90))||((secretcode>=97)&&(secretcode<=122)))?controler:controler++,controler);//Controlling the input is true variable, if it is not take another input

                volunteer=secretcode;//Start of binarylization
                for(binaried=0,changer=1;volunteer>0;changer*=10,volunteer/=2){//writing secret code in integer but in binary(zeros&ones)
                    binaried=binaried+(volunteer%2)*changer;
                }
                printf("Binary equivalent of the chosen code is %d\n",binaried);

                secretZero=(binaried%2)==1 ? '1':'0';
                secretOne=(binaried/10)%2==1 ? '1':'0';
                secretTwo=(binaried/100)%2==1 ? '1':'0';
                secretThree=(binaried/1000)%2==1 ? '1':'0';
                secretFour=(binaried/10000)%2==1 ? '1':'0';
                secretFive=(binaried/100000)%2==1 ? '1':'0';
                secretSix=(binaried/1000000)%2==1 ? '1':'0';
                secretSeven=(binaried/10000000)%2==1 ? '1':'0';//secret code is char and in binary

                break;

            case 2://Encoding starts
                printf("\nYou have chosen option 2!\n");
                do{
                    printf("\nWhich base will you use to enter text (base 16/2)? ");
                    scanf("\n%d",&baseSelect);
                    if(baseSelect==2){//The perfect code doesn't exist
                        do{
                                printf("Please enter the text to encrypt: ");

                                differentInput=0;
                                baseTwoBinaryZero='0',baseTwoBinaryOne='0',baseTwoBinaryTwo='0',baseTwoBinaryThree='0',baseTwoBinaryFour='0',baseTwoBinaryFive='0',baseTwoBinarySix='0',baseTwoBinarySeven='0';
                                scanf("\n%c",&baseTwoBinarySeven);
                                scanf("%c",&baseTwoBinarySix);
                                scanf("%c",&baseTwoBinaryFive);
                                scanf("%c",&baseTwoBinaryFour);
                                scanf("%c",&baseTwoBinaryThree);
                                scanf("%c",&baseTwoBinaryTwo);
                                scanf("%c",&baseTwoBinaryOne);
                                scanf("%c",&baseTwoBinaryZero);

                                if((baseTwoBinarySeven!='0' && baseTwoBinarySeven!='1')||(baseTwoBinarySix!='0' && baseTwoBinarySix!='1')||(baseTwoBinaryFive!='0' && baseTwoBinaryFive!='1')||(baseTwoBinaryFour!='0' && baseTwoBinaryFour!='1')||(baseTwoBinaryThree!='0' && baseTwoBinaryThree!='1')||(baseTwoBinaryTwo!='0' && baseTwoBinaryTwo!='1')||(baseTwoBinaryOne!='0' && baseTwoBinaryOne!='1')||(baseTwoBinaryZero!='0' && baseTwoBinaryZero!='1')){
                                    differentInput=1;
                                }//Checking all of them 1||0

                                if(baseTwoBinaryZero=='0'&&baseTwoBinaryOne=='0'&&baseTwoBinaryTwo=='0'&&baseTwoBinaryThree=='0'&&baseTwoBinaryFour=='0'&&baseTwoBinaryFive=='0'&&baseTwoBinarySix=='0'&&baseTwoBinarySeven=='0'){
                                    continue;
                                }

                                if(differentInput==1){
                                    printf("\nInvalid text, ");
                                    continue;
                                }

                                encryptedZero='0'/*F for first encrypted*/,encryptedOne='0',encryptedTwo='0',encryptedThree='0',encryptedFour='0',encryptedFive='0',encryptedSix='0',encryptedSeven='0';
                                encryptedZero=(baseTwoBinaryZero==secretZero)? '0':'1';//encryptilization
                                encryptedOne=(baseTwoBinaryOne==secretOne)? '0':'1';
                                encryptedTwo=(baseTwoBinaryTwo==secretTwo)? '0':'1';
                                encryptedThree=(baseTwoBinaryThree==secretThree)? '0':'1';
                                encryptedFour=(baseTwoBinaryFour==secretFour)? '0':'1';
                                encryptedFive=(baseTwoBinaryFive==secretFive)? '0':'1';
                                encryptedSix=(baseTwoBinarySix==secretSix)? '0':'1';
                                encryptedSeven=(baseTwoBinarySeven==secretSeven)? '0':'1';

                                binaried=(encryptedSeven=='1')? 1:0;//Start of debinarylization(decimalization)
                                binaried=(encryptedSix=='1')? binaried*10+1:binaried*10;
                                binaried=(encryptedFive=='1')? binaried*10+1:binaried*10;
                                binaried=(encryptedFour=='1')? binaried*10+1:binaried*10;
                                binaried=(encryptedThree=='1')? binaried*10+1:binaried*10;
                                binaried=(encryptedTwo=='1')? binaried*10+1:binaried*10;
                                binaried=(encryptedOne=='1')? binaried*10+1:binaried*10;
                                binaried=(encryptedZero=='1')? binaried*10+1:binaried*10;
                                for(volunteer=0,counttoEight=0;counttoEight<=7;binaried/=10,counttoEight++){
                                    volunteer=volunteer+((binaried%2)*pow(2,counttoEight));
                                }
                                resultedChar=volunteer;
                                printf("\nYour Encoded text is: %c",resultedChar);

                                while(baseTwoBinaryZero!='0'||baseTwoBinaryOne!='0'||baseTwoBinaryTwo!='0'||baseTwoBinaryThree!='0'||baseTwoBinaryFour!='0'||baseTwoBinaryFive!='0'||baseTwoBinarySix!='0'||baseTwoBinarySeven!='0'){//continue to read
                                    differentInput=0;
                                    baseTwoBinaryZero='0',baseTwoBinaryOne='0',baseTwoBinaryTwo='0',baseTwoBinaryThree='0',baseTwoBinaryFour='0',baseTwoBinaryFive='0',baseTwoBinarySix='0',baseTwoBinarySeven='0';
                                    scanf("%c",&baseTwoBinarySeven);//reading and check if it is new line or not
                                    if(baseTwoBinarySeven==10){
                                        baseTwoBinarySeven='0';
                                        break;
                                    }
                                    scanf("%c",&baseTwoBinarySix);
                                    if(baseTwoBinarySix==10){
                                        baseTwoBinarySix='0';
                                        break;
                                    }
                                    scanf("%c",&baseTwoBinaryFive);
                                    if(baseTwoBinaryFive==10){
                                        baseTwoBinaryFive='0';
                                        break;
                                    }
                                    scanf("%c",&baseTwoBinaryFour);
                                    if(baseTwoBinaryFour==10){
                                        baseTwoBinaryFour='0';
                                        break;
                                    }
                                    scanf("%c",&baseTwoBinaryThree);
                                    if(baseTwoBinaryThree==10){
                                        baseTwoBinaryThree='0';
                                        break;
                                    }
                                    scanf("%c",&baseTwoBinaryTwo);
                                    if(baseTwoBinaryTwo==10){
                                        baseTwoBinaryTwo='0';
                                        break;
                                    }
                                    scanf("%c",&baseTwoBinaryOne);
                                    if(baseTwoBinaryOne==10){
                                        baseTwoBinaryOne='0';
                                        break;
                                    }
                                    scanf("%c",&baseTwoBinaryZero);
                                    if(baseTwoBinaryZero==10){
                                        baseTwoBinaryZero='0';
                                        break;
                                    }

                                    if((baseTwoBinarySeven!='0' && baseTwoBinarySeven!='1')||(baseTwoBinarySix!='0' && baseTwoBinarySix!='1')||(baseTwoBinaryFive!='0' && baseTwoBinaryFive!='1')||(baseTwoBinaryFour!='0' && baseTwoBinaryFour!='1')||(baseTwoBinaryThree!='0' && baseTwoBinaryThree!='1')||(baseTwoBinaryTwo!='0' && baseTwoBinaryTwo!='1')||(baseTwoBinaryOne!='0' && baseTwoBinaryOne!='1')||(baseTwoBinaryZero!='0' && baseTwoBinaryZero!='1')){
                                        differentInput=1;
                                    }//Checking all of them 1||0

                                    /*if(baseTwoBinaryZero=='0'&&baseTwoBinaryOne=='0'&&baseTwoBinaryTwo=='0'&&baseTwoBinaryThree=='0'&&baseTwoBinaryFour=='0'&&baseTwoBinaryFive=='0'&&baseTwoBinarySix=='0'&&baseTwoBinarySeven=='0'){
                                        continue;
                                    }*/
                                    if(differentInput==1){
                                        printf("\r\nInvalid text, ");
                                        continue;
                                    }
                                    encryptedZero='0',encryptedOne='0',encryptedTwo='0',encryptedThree='0',encryptedFour='0',encryptedFive='0',encryptedSix='0',encryptedSeven='0';
                                    encryptedZero=(baseTwoBinaryZero==secretZero)? '0':'1';//encryptilization
                                    encryptedOne=(baseTwoBinaryOne==secretOne)? '0':'1';
                                    encryptedTwo=(baseTwoBinaryTwo==secretTwo)? '0':'1';
                                    encryptedThree=(baseTwoBinaryThree==secretThree)? '0':'1';
                                    encryptedFour=(baseTwoBinaryFour==secretFour)? '0':'1';
                                    encryptedFive=(baseTwoBinaryFive==secretFive)? '0':'1';
                                    encryptedSix=(baseTwoBinarySix==secretSix)? '0':'1';
                                    encryptedSeven=(baseTwoBinarySeven==secretSeven)? '0':'1';

                                    binaried=(encryptedSeven=='1')? 1:0;//Start of binarylization
                                    binaried=(encryptedSix=='1')? binaried*10+1:binaried*10;
                                    binaried=(encryptedFive=='1')? binaried*10+1:binaried*10;
                                    binaried=(encryptedFour=='1')? binaried*10+1:binaried*10;
                                    binaried=(encryptedThree=='1')? binaried*10+1:binaried*10;
                                    binaried=(encryptedTwo=='1')? binaried*10+1:binaried*10;
                                    binaried=(encryptedOne=='1')? binaried*10+1:binaried*10;
                                    binaried=(encryptedZero=='1')? binaried*10+1:binaried*10;
                                    for(volunteer=0,counttoEight=0;counttoEight<=7;binaried/=10,counttoEight++){
                                        volunteer=volunteer+((binaried%2)*pow(2,counttoEight));
                                    }
                                    resultedChar=volunteer;
                                    printf("%c",resultedChar);
                                }
                        }while(differentInput==1);
                        break;


                    }

                    else if(baseSelect==16){

                            do{
                                fflush(stdin);//clear buffer
                                sumOfBase16Decimals=0;
                                printf("Please enter the text to encrypt: ");
                                do{
                                        scanf("%c",&firstScannedChar);
                                        if(firstScannedChar==10)//if new line entered it will stop
                                            break;
                                        if(((firstScannedChar<49)||(firstScannedChar>57))&&((firstScannedChar<65)||(firstScannedChar>70))){//is it in 1-9 or a-f interval
                                            printf("\nInvalid text! ");
                                            break;
                                        }
                                        scanf("%c",&secondScannedChar);
                                        if(((secondScannedChar<48)||(secondScannedChar>57))&&((secondScannedChar<65)||(secondScannedChar>70))){//is it in 0-9 or a-f interval
                                            printf("\nerror(sadece 1 elemanda girmis olabilir veya baska bir eleman)\n");
                                            break;
                                        }

                                        if(firstScannedChar==49){//1
                                            firstDecimal=1;
                                        }
                                        else if(firstScannedChar==50){//2
                                            firstDecimal=2;
                                        }
                                        else if(firstScannedChar==51){//3
                                            firstDecimal=3;
                                        }
                                        else if(firstScannedChar==52){//4
                                            firstDecimal=4;
                                        }
                                        else if(firstScannedChar==53){//5
                                            firstDecimal=5;
                                        }
                                        else if(firstScannedChar==54){//6
                                            firstDecimal=6;
                                        }
                                        else if(firstScannedChar==55){//7
                                            firstDecimal=7;
                                        }
                                        else if(firstScannedChar==56){//8
                                            firstDecimal=8;
                                        }
                                        else if(firstScannedChar==57){//9
                                            firstDecimal=9;
                                        }
                                        else if(firstScannedChar==65){//A
                                            firstDecimal=10;
                                        }
                                        else if(firstScannedChar==66){//B
                                            firstDecimal=11;
                                        }
                                        else if(firstScannedChar==67){//C
                                            firstDecimal=12;
                                        }
                                        else if(firstScannedChar==68){//D
                                            firstDecimal=13;
                                        }
                                        else if(firstScannedChar==69){//E
                                            firstDecimal=14;
                                        }
                                        else if(firstScannedChar==70){//F
                                            firstDecimal=15;
                                        }


                                        if(secondScannedChar==48){//0
                                            secondDecimal=0;
                                        }
                                        else if(secondScannedChar==49){//1
                                            secondDecimal=1;
                                        }
                                        else if(secondScannedChar==50){//2
                                            secondDecimal=2;
                                        }
                                        else if(secondScannedChar==51){//3
                                            secondDecimal=3;
                                        }
                                        else if(secondScannedChar==52){//4
                                            secondDecimal=4;
                                        }
                                        else if(secondScannedChar==53){//5
                                            secondDecimal=5;
                                        }
                                        else if(secondScannedChar==54){//6
                                            secondDecimal=6;
                                        }
                                        else if(secondScannedChar==55){//7
                                            secondDecimal=7;
                                        }
                                        else if(secondScannedChar==56){//8
                                            secondDecimal=8;
                                        }
                                        else if(secondScannedChar==57){//9
                                            secondDecimal=9;
                                        }
                                        else if(secondScannedChar==65){//A
                                            secondDecimal=10;
                                        }
                                        else if(secondScannedChar==66){//B
                                            secondDecimal=11;
                                        }
                                        else if(secondScannedChar==67){//C
                                            secondDecimal=12;
                                        }
                                        else if(secondScannedChar==68){//D
                                            secondDecimal=13;
                                        }
                                        else if(secondScannedChar==69){//E
                                            secondDecimal=14;
                                        }
                                        else if(secondScannedChar==70){//F
                                            secondDecimal=15;//F=15 in base 16
                                        }

                                        sumOfBase16Decimals=sumOfBase16Decimals*(pow(16,2))+firstDecimal*16+secondDecimal;//loop ici decimal cevirici her seferinde eskisini 16 nin karesi ile carparak yenisi ile topluyor

                                }while((((firstScannedChar>=49)&&(firstScannedChar<=57))||((firstScannedChar>=65)&&(firstScannedChar<=70)))&&(((secondScannedChar>=48)&&(secondScannedChar<=57))||((secondScannedChar>=65)&&(secondScannedChar<=70))));//if th input is true takes the new two input
                                if(firstScannedChar==10){//if new line entered it will stop and exit from loop
                                    break;
                                }
                            }while((((firstScannedChar<49)||(firstScannedChar>57))&&((firstScannedChar<65)||(firstScannedChar>70))) || (((secondScannedChar<48)||(secondScannedChar>57))&&((secondScannedChar<65)||(secondScannedChar>70))));//if the input is wrong takes another input
                            //printf("Resuşt decimal:%d\n",sumOfBase16Decimals);

                            volunteer=sumOfBase16Decimals;//Start of binarylization
                            for(binaried=0,changer=1;volunteer>0;changer*=10,volunteer/=2){
                                binaried=binaried+(volunteer%2)*changer;
                            }
                            //printf("binaried:%d.\n",binaried);

                            baseSixteenBinaryZero=(binaried%2)==1 ? '1':'0';
                            baseSixteenBinaryOne=(binaried/10)%2==1 ? '1':'0';
                            baseSixteenBinaryTwo=(binaried/100)%2==1 ? '1':'0';
                            baseSixteenBinaryThree=(binaried/1000)%2==1 ? '1':'0';
                            baseSixteenBinaryFour=(binaried/10000)%2==1 ? '1':'0';
                            baseSixteenBinaryFive=(binaried/100000)%2==1 ? '1':'0';
                            baseSixteenBinarySix=(binaried/1000000)%2==1 ? '1':'0';
                            baseSixteenBinarySeven=(binaried/10000000)%2==1 ? '1':'0';

                            encryptedZero='0',encryptedOne='0',encryptedTwo='0',encryptedThree='0',encryptedFour='0',encryptedFive='0',encryptedSix='0',encryptedSeven='0';
                            encryptedZero=(baseSixteenBinaryZero==secretZero)? '0':'1';//encryptilization
                            encryptedOne=(baseSixteenBinaryOne==secretOne)? '0':'1';
                            encryptedTwo=(baseSixteenBinaryTwo==secretTwo)? '0':'1';
                            encryptedThree=(baseSixteenBinaryThree==secretThree)? '0':'1';
                            encryptedFour=(baseSixteenBinaryFour==secretFour)? '0':'1';
                            encryptedFive=(baseSixteenBinaryFive==secretFive)? '0':'1';
                            encryptedSix=(baseSixteenBinarySix==secretSix)? '0':'1';
                            encryptedSeven=(baseSixteenBinarySeven==secretSeven)? '0':'1';

                            binaried=(encryptedSeven=='1')? 1:0;//Start of binarylization
                            binaried=(encryptedSix=='1')? binaried*10+1:binaried*10;
                            binaried=(encryptedFive=='1')? binaried*10+1:binaried*10;
                            binaried=(encryptedFour=='1')? binaried*10+1:binaried*10;
                            binaried=(encryptedThree=='1')? binaried*10+1:binaried*10;
                            binaried=(encryptedTwo=='1')? binaried*10+1:binaried*10;
                            binaried=(encryptedOne=='1')? binaried*10+1:binaried*10;
                            binaried=(encryptedZero=='1')? binaried*10+1:binaried*10;
                            for(volunteer=0,counttoEight=0;counttoEight<=7;binaried/=10,counttoEight++){
                                volunteer=volunteer+((binaried%2)*pow(2,counttoEight));
                            }
                            printf("\nYour Encoded text's integer version is: %d\n",volunteer);
                            resultedChar=(char)volunteer;
                            printf("\nYour Encoded text's character version is: %c\n",resultedChar);/*(I wrote an explanation for two printfs but my English fall short, so I wrote it in Turkish)
                            (Moreover, I wrote an e-mail to Yeliz Hoca for my doubt)
                            encodelanmis hali char olmasi gerektigini dusunuyorum eger encodelanmis halini integer verirsem
                            encode'u ascii tabledan kontrol etmesi gerektigini dusunuyorum base 2'da o zaman ALE/CNG gibi outputlar vermemesi gerekiyor
                            gonderilen sample runlara uymadigi icin yazdim*/

                        break;
                    }
                    else
                        printf("Sorry, That's not in our bases.\n");
                }while(baseSelect!=2 && baseSelect!=16);

            case 3:
                break;
            default:
                printf("Sorry, That's not in our options.\n");
        }
    }while(option!=3);
    return 0;
}
