
 //rar a -hp1 tecmint.rar test
 //unrar e -hp1 tecmint.rar 

// TODO:
// random generated passwords (no char array)
// user says, where the path with the pics is
// Note: this folder will be removed after archiving

 
#include <stdio.h>      //puts, printf
#include <time.h>       // time_t, struct tm, time, localtime 
#include <string.h>

#define SIZE 0x100
#define SIZE2 0x100
#define SIZE3 0x100
#define ADV 24

time_t t;
    char day[SIZE];
    char month[SIZE2];
    char year[SIZE3];
    struct tm ltime;
    
    char* pw[ADV] =
    {
		"ihmXQwimdfsfgggIzfEG0",
		"5Dw6l897iPZguc1ZnGTt5",
		"eDWEKW5c2Rfj3ajfo51Rs",
		"3cmzhNJri5kNLRBJn9GRj",
		"vx5ejjrRfEyhYaqwc9eOm",
		"T2o1CiATXxIsdfasUlYjq",
		"U4glfBOJZDjTyiMafFffb",
		"0UhbRuBj3qFZ0alBdBS48",
		"ynJkrIo8sfswdfdszXAFw",
		"qkAKf2uzdfgddfjRGAnYv",
		"OOIPAMvdfsagb4QFngVV9",
		"1LSEIFfTlIMjaQqfH5trq",
		"S0s0EPLimRadfsfdfds3p",
		"CqhHpsmNdfgdfgdjOl2gy",
		"dhwndfgdfgdxszbHX5SuZ",
		"iChdntwSq7CubjpkrGBaP",
		"dlIIb2HlUwnLVVfZu3RoH",
		"A9p9bTFLPS8TuUq7eGapÜ",
		"Y5UFNCfoM7l4ZNLgN2Hz3",
		"NXV7xRbrFxRbzriKO7XWe",
		"sFCfNzAVbPbL4RmYM6bGX",
		"i1pZZ3yIpCIR6GqMLrBwT",	
		"Y61Yv4klKCJJvt0yy6dnc",
		"xEAfiTiVdfslöwele25gI",
	
		
	};

void cr_archives(char* pwmain)
{
	
	
	char cr_archive1 [200];
	char cr_archive2 [200];
	unsigned int i;	
	
	printf("Please put your pics in the folder pics and name them 1.jpg 2.jpg, etc..\n");
	printf("You can also put  in other stuff than pics, but name them also with a number before the extension!\n");
	system("mkdir -p pics");
	printf("Please wait some time, the programm is doing the archiving work for you!\n");
	
	//printf("You need to give the archive a password: \n");
	//scanf("%s",pwmain);
	
	
		
	for(i=1; i<ADV+1; i++)
	{
		snprintf ( cr_archive1, 100, "cd  pics && rar a -inul -hp%s -o- %i.rar %i.*", pw[i-1],  i, i);
		system(cr_archive1);	
	}
		
	//snprintf (cr_archive2, 100, "cd pics && rar a -inul -hp%s -o- ../adv.rar *.rar", pwmain);	
	snprintf (cr_archive2, 100, "cd pics && rar a -inul -hpxmas%s -o- ../adv.rar *.rar", year);	
	system(cr_archive2);	
	system("rm -r pics");
}


void extraction(char* pwmain)
{
	
	if(strcmp("December", month) == 0);//&& atoi(day) < ADV+1)
	{
		if(atoi(day)<ADV+1)
		{
			
			printf("Viel Spaß mit dem heutigen Türchen! :) \n");
			printf("Heutiges Passwort: %s\n\n", pw[atoi(day)-1]);
			
		}

		system("mkdir -p tuerchen");
		
		int i;
		for(i=1; i<atoi(day); i++)
		{
			char extract1 [150];
			snprintf ( extract1, 150, "unrar e -inul -hpxmas%s -o- adv.rar %i.rar tuerchen", year, i);
			system(extract1);
			
			char extract2 [150];
			snprintf ( extract2, 150, "cd tuerchen && unrar e -inul -hp%s -o- %i.rar", pw[i-1],  i );
			system(extract2);
			system("rm tuerchen/*.rar 2> /dev/null");
		}
		
		printf("Vorherige Passwörter\n");
				
		for(i=1; i<atoi(day); i++)
			printf("Türchen %i: %s\n", i, pw[i-1]);
			
					
	}	
		
}


int main (int argc, char *argv[])
{


    t = time (0);
    localtime_r (& t, & ltime);
    
    
    strftime (day, SIZE, "%e", & ltime);
    strftime (month, SIZE2, "%B", & ltime);
    strftime (year, SIZE3, "%Y", & ltime);
    
    char pwmain[999];
   
    
    switch(argc)
    {	
		case 1:
			extraction(pwmain);
			break;
			
		case 2:
			if(strcmp(argv[1], "create")== 0)
				cr_archives(pwmain);
			if(strcmp(argv[1], "extract")== 0)
				extraction(pwmain);
			if(strcmp(argv[1], "-h")== 0)
			{
				printf("Usage:\n");
				printf("%s or %s extract: open the  doors\n", argv[0], argv[0]);
				printf("%s create: create  the archives\n", argv[0]);
			}
			
			break;
				
				
		default:
			break;
			
		}
		
    return 0;
}
