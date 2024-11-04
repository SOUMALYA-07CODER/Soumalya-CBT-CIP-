#include<stdio.h>

void File_content(FILE *, int *, int *, int *);

int main(void)
{
	char file_name[100];
	FILE *fp;
	int char_count=0, word_count=0, line_count=0;
	
	printf("Enter the file name : ");
	gets(file_name);
	
	fp = fopen(file_name, "r+");
	
	if(fp == NULL)
	{
		printf("\nFile Not Present....\n");
		return 0;
	}
	else
	{
		File_content(fp, &char_count, &word_count, &line_count);
		printf("\nTotal Number Of Characters In File Is : %d", char_count-1);
		printf("\nTotal Number Of words Is : %d", word_count);
		printf("\nTotal Number Of Lines Is : %d", line_count);
		
	}
	return 0;
}

void File_content(FILE *fp, int *char_count, int *word_count, int *line_count)
{
	char ch;
	
	*char_count = 0;
	*word_count = 0;
	*line_count = 0;
	while((ch=fgetc(fp))!=EOF)
	{
		*char_count = (*char_count)+1;
		
		if(ch == ' ' || ch == '\t' || ch == '\n')
			*word_count = (*word_count)+1;
		
		if(ch == '?' || ch == '.' || ch == '!')
			*line_count = (*line_count)+1;
	}
}
