#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<io.h>
int main(int argc, char* argv[])
{ 
	//计算单词数
	int countWord(char *file);
	//计算字符数
	int countChar(char *file);
	//计算行数
	int countLine(char *file);
	//空行
    int count_blankLine(char *file);
	//代码行
	int count_codeLine(char *file);
	//注释行
    int count_noteLine(char *file);
	//递归找符合条件的文件
    void Scan(char *file, char type);
	//将内容输出到outputFile.txt文件中
	void printFile(char *file,int result,char type);
	int cw=0,cc=0,cl=0,cb=0,ccl=0,cn=0;
	FILE *fp;
    char type='c';
	while(1==1){
		//printf("请输入可执行文件名\n");
		//printf("请输入想要进行的操作（-w表示计算单词数 -c表示计算字符数 -l表示计算行数 -a表示计算空行 代码行 注释行 -s表示符合条件的文件数）\n");
		//printf("请输入想要操作的文件名\n");
		scanf("%s %s %s",argv[0],argv[1],argv[2]);//argv[0] 可执行程序的文件名argv[1] 指令，argv[2]文件名
		if((fp=fopen(argv[2],"r"))==NULL){
		   printf("文件不存在\n\n");
           //scanf("%s %s %s",argv[0],argv[1],argv[2]);//argv[0] 可执行程序的文件名argv[1] 指令，argv[2]文件名
		   continue;
		}
		else 
		{
		   if(!strcmp(argv[1],"-w"))//判断字符串是否相等
		   {
		     int cw=countWord(argv[2]);
		     
		   }
		   if(!strcmp(argv[1],"-c"))
		   {
		   int cc=countChar(argv[2]);
		   
		   }
	      if(!strcmp(argv[1],"-l"))
		  {
		   int cl=countLine(argv[2]);
		   
		  }
		 if(!strcmp(argv[1],"-a"))//代码、空行、注释
		 {
		  int cb=count_blankLine(argv[2]);
		  int ccl=count_codeLine(argv[2]);
		  int cn=count_noteLine(argv[2]);
		  
		 }
		 if(!strcmp(argv[1],"-s"))//递归目录下符合条件的文件
		 {
		     Scan(argv[2],type);
		 }
		 if(!strcmp(argv[1],"-o"))
		 {
		    printFile(argv[2],cw,'w');
			printFile(argv[2],cc,'c');
			printFile(argv[2],cl,'l');
			printFile(argv[2],cb,'e');
		    printFile(argv[2],ccl,'f');
		    printFile(argv[2],cn,'g');
		 }

		}
		 
     fclose(fp);   	
	}
	return 0;
}

	//计算单词数
    int countWord(char *file)
	{
		FILE *fp;
		int wCount=0;
		int is_word=0;
		char a;
		fp=fopen(file,"r");
		if(fp==NULL){
		  printf("文件打开失败\n");
		}else{
			while(!feof(fp)){
				a=fgetc(fp);
				if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||a=='_')
					is_word=1;
				else if(is_word){
				     wCount++;
					 is_word=0;
				}
				}
			}
		fclose(fp);
		printf("该文件单词数为：%d\n",wCount);
		return wCount;
	}
	//计算字符数
	int countChar(char *file)
	{
		FILE *fp;
		fp=fopen(file,"r");
		char a;
		int cCount=0;
		if(NULL==fp)
		{
		  printf("文件为空\n");
		}else{
			while((a=fgetc(fp))!=EOF){
				  cCount++;
			}
		}
	  fclose(fp);
	   printf("字符数为:%d\n",cCount);
	   return cCount;
	}
	//计算行数
	int countLine(char *file)
	{
		FILE *fp;
		fp=fopen(file,"r");
		int lCount=0;
		char a;
		if(NULL==fp)
		{
		  printf("文件为空\n");
		}else{
			while((a=fgetc(fp))!=EOF){
			  if(a=='\n')
				  lCount++;
			}
		}
		fclose(fp);
	   printf("文件总行数为：%d\n",lCount); 
	   return lCount;
	}
	//空行
    int count_blankLine(char *file)
	{
	   FILE *f;
      int blCount= 0;
      int ch_num = 0;
      char ch;
      f = fopen(file, "r");
       if(NULL==(f=fopen(file,"r")))
	   {
       printf("文件为空");
	   }
       else
           while (!feof(f))
		   {
             ch= fgetc(f);
             if (ch=='\n'){
                if (ch_num<= 1)
                    blCount++;
                    ch_num = 0;
			 }
             else if (ch!=' '&&ch!='\t')
                    ch_num++;
		   }
       fclose(f);
	   printf("文件空行为:%d\n ",blCount);
	   return blCount;
	}
	//代码行
	int count_codeLine(char *file)
	{   
		FILE *fp;
		fp=fopen(file,"r");
		int clCount=0;
		char a;
		if(NULL==fp)
		{
		  printf("文件为空\n");
		}else{
			while((a=fgetc(fp))!=EOF){
				 if(a==';')
					 clCount++;	  
			}
		}
		fclose(fp);
	   printf("文件代码行数为：%d\n",clCount);  
	   return clCount;
	}
	//注释行
    int count_noteLine(char *file)
	{
	    FILE *f;
        int ch_num = 0;
		int nlCount=0;
        char ch;
        f=fopen(file, "r");
        if(NULL==(f=fopen(file,"r")))
		{
         printf("文件为空\n");
		}
      else
         while (!feof(f))
		 {
              ch= fgetc(f);
              if(ch=='\n')
			  {
				  if(ch_num==2) 
					  nlCount++;
				      ch_num=0;
			  }
             else if(ch=='/') 
				 ch_num++;
             else if(ch_num==1)
			 {
				 if(ch=='/') 
					 ch_num++;
			 } 
		 } 
       fclose(f);
       printf("文件注释行为:%d\n ",nlCount);
	   return nlCount;
	}
	//递归找符合条件的文件
   void Scan(char *Path, char Type) {
	char *FileName = NULL;
	char *FileType = NULL;
	char Temp[30];	//用于暂存改变得字符串
	long Head;
	struct _finddata_t FileData;
	int i = 0;

	FileName = Path;
	while (*(Path + i) != '\0') {	//找出文件名和文件类型的位置
		if (*(Path + i) == '\\')
			FileName = Path + i + 1;
		if (*(Path + i) == '.')
			FileType = Path + i + 1;
		i++;
	}
	
	strcpy(Temp, FileType);//调整字符串
	*FileType = '*';
	*(FileType + 1) = '\0';
	
	Head = _findfirst(Path, &FileData);
	
	strcpy(FileType, Temp);//恢复字符串

	do {
		if ( !strcmp(FileData.name, "..") || !strcmp(FileData.name, "."))	//去除前驱文件路径
			continue;
		
		if (_A_SUBDIR == FileData.attrib)	//是文件夹
		{	
			strcpy(Temp, FileName);	//调整字符串
			for (i = 0; *(FileData.name + i) != '\0'; i++) {
				*(FileName + i) = *(FileData.name + i);
			}
			*(FileName + i) = '\\';
			*(FileName + i + 1) = '\0';
			strcat(Path, Temp);

			Scan(Path, Type);

			strcpy(FileName, Temp);	//恢复字符串			
		}
		else//是文件 
		{	
			for (i = 0; *(FileData.name + i) != '.'; i++);
			if (!strcmp(FileData.name + i + 1, FileType)) {	//是指定类型的文件
				
				strcpy(Temp, FileName);
				strcpy(FileName, FileData.name); //调整字符串
				
			printf("%s:  ", FileData.name);
				//Run(Type, NULL, Path);	//将地址及功能传到启动函数
				printf("\n");

				strcpy(FileName, Temp);//恢复字符串
			}
		}
	} while (_findnext(Head, &FileData) == 0);

	_findclose(Head);	
}
	void printFile(char *file,int result,char type){
	  FILE *wp;
	  if((wp=fopen("outputFile.txt","a"))==NULL){
		   printf("文件不存在\n\n");
	  }else{
		  switch(type){
		  case 'c':
			      fprintf(wp, "%s文件中字符数有%d", file,result);
			        break;
		  case 'w':fscanf(wp, "%s文件中单词数有%d", file,result);
			       fprintf(wp, "%s文件中单词数有%d", file,result);
			       break;
		  case 'l':
			       fprintf(wp, "%s文件中总行数数有%d", file,result);
			       break;
		  case 'f':
			       fprintf(wp, "%s文件中代码行数有%d", file,result);
				   break;
		  case 'e':
			      fprintf(wp, "%s文件中空行数有%d", file,result);
				  break;
		  case 'g':
			       fprintf(wp, "%s文件中注释数有%d", file,result);break;
		  default:; break;
		  }   
	  }
     fclose(wp);
	}

	