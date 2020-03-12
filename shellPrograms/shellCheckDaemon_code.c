#include "shellPrograms.h"

/*  A program that prints how many summoned daemons are currently alive */
int shellCheckDaemon_code()
{

   /* TASK 8 */
   //Create a command that trawl through output of ps -efj and contains "summond"
   char *command = malloc(sizeof(char) * 256);
   sprintf(command, "ps -efj | grep summond  | grep -v tty > output.txt");
   // TODO: Execute the command using system(command) and check its return value
   if (system(command) == -1){
      fprintf(stderr, "Failed to execute the command\n");
      exit(1);
   }
   int live_daemons = 0;
   // TODO: Analyse the file output.txt, wherever you set it to be. You can reuse your code for countline program
   // 1. Open the file
   FILE *fp = fopen("output.txt","r");
   // 2. Fetch line by line using getline()
   char *buffer = NULL;
   size_t size = 256;
    while ( getline(&buffer, &size, fp)!=-1)
    {
      // 3. Increase the daemon count whenever we encounter a line
        live_daemons++;
    }
    live_daemons--;
   // 4. Close the file
   // 5. print your result
   if (live_daemons == 0)
      printf("No daemon is alive right now\n");
   else
   {
      printf("There are in total of %d live daemons \n", live_daemons);
   }
   free(command);
    // 6. Close the FILE*
    fclose(fp);
   // TODO: close any file pointers and free any statically allocated memory 

   return 1;
}

int main(int argc, char **args)
{
   return shellCheckDaemon_code();
}