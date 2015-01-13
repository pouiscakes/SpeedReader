#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char article[] = "There have been 55 million abortions in the US since 1973. Something in the ballpark of 45% of women who have abortions have more than one abortion. These people would have been raised by their incompetent parents to drain down society, increase crime rates, suck up resources, and generally screw things up. Various ways to lower a resource negative population would have to be explored, if not because of this 55 million, then because of the next 55 million. One possibility is that there would be wars waged to try to kill them all, perhaps even with other countries with similar problems. Waging war to purposefully lower population, even with a country facing similar issues, would cost not only resources, but it would also cause political, cultural, and global issues. America's innovation and education rankings would be lower. Every middle-class child in the country would receive a lower quality education if there were 55 million more around. (Note:I'm not trying to hear arguments on the ethics of abortion, its a banal argument that everyone and their mother has had at one point, what I am really fishing for is insight into what the country would look like with those 55 million around. Would we adapt to the population and make good use of each of them?)";

    printf("-------\nOriginal article:\n\n%s\n-------\n", article);



    char words[1000][20];
    int wordcount = 0;

    char temp[20];
    int tempcount = 0;


    for(int i = 0; i<=strlen(article); i++) {
        if(article[i]!=' ' && article[i]!=NULL) {
            temp[tempcount]=article[i];
            tempcount++;
        }
        else{
            strcpy(words[wordcount],temp);
            wordcount++;
            memset(temp,0,strlen(temp));
            tempcount = 0;
        }
    }

    /*
    //tab align
    for(int i = 0; i < wordcount-2; i++){
        printf("\n---------\n---------\n---------\n");
        printf("%s",words[i]);
        if(strlen(words[i])<8) printf("\t");
        printf("\t%s",words[i+1]);
        if(strlen(words[i+1])<8) printf("\t");
        printf("\t%s",words[i+2]);
        printf("\n---------\n---------\n---------\n");
        usleep(100*1000);
    }*/

    //smart align
    char aligned[] = "                                                                           ";
    for(int i = 0; i < wordcount-2; i++){

        //middle word
        for(int j = 0; j < strlen(words[i+1]); j++) {
            aligned[20+j] = words[i+1][j];
        }
        //first word
        for(int j = 0; j < strlen(words[i]); j++) {
            aligned[j + 19-strlen(words[i])] = words[i][j];
        }
        //last word
        for(int j = 0; j < strlen(words[i+2]); j++) {
            aligned[21 + j + strlen(words[i+1])] = words[i+2][j];
        }
        printf("\n---------\n---------\n---------\n---------\n---------           v\n");
        printf("%s\n",aligned);
        printf("\n---------           ^\n---------\n---------\n---------\n---------\n---------\n---------\n---------\n---------");
        memset(aligned,' ',strlen(aligned));
        if(words[i+1][strlen(words[i+1])-1]=='.' ||words[i+1][strlen(words[i+1])-1]==','||words[i+1][strlen(words[i+1])-1]=='?') usleep(200*1000);
        usleep(100*1000);
    }



    return 0;

}
