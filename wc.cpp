#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<io.h>
int main(int argc, char* argv[])
{ 
	//���㵥����
	int countWord(char *file);
	//�����ַ���
	int countChar(char *file);
	//��������
	int countLine(char *file);
	//����
    int count_blankLine(char *file);
	//������
	int count_codeLine(char *file);
	//ע����
    int count_noteLine(char *file);
	//�ݹ��ҷ����������ļ�
    void Scan(char *file, char type);
	//�����������outputFile.txt�ļ���
	void printFile(char *file,int result,char type);
	int cw=0,cc=0,cl=0,cb=0,ccl=0,cn=0;
	FILE *fp;
    char type='c';
	while(1==1){
		//printf("�������ִ���ļ���\n");
		//printf("��������Ҫ���еĲ�����-w��ʾ���㵥���� -c��ʾ�����ַ��� -l��ʾ�������� -a��ʾ������� ������ ע���� -s��ʾ�����������ļ�����\n");
		//printf("��������Ҫ�������ļ���\n");
		scanf("%s %s %s",argv[0],argv[1],argv[2]);//argv[0] ��ִ�г�����ļ���argv[1] ָ�argv[2]�ļ���
		if((fp=fopen(argv[2],"r"))==NULL){
		   printf("�ļ�������\n\n");
           //scanf("%s %s %s",argv[0],argv[1],argv[2]);//argv[0] ��ִ�г�����ļ���argv[1] ָ�argv[2]�ļ���
		   continue;
		}
		else 
		{
		   if(!strcmp(argv[1],"-w"))//�ж��ַ����Ƿ����
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
		 if(!strcmp(argv[1],"-a"))//���롢���С�ע��
		 {
		  int cb=count_blankLine(argv[2]);
		  int ccl=count_codeLine(argv[2]);
		  int cn=count_noteLine(argv[2]);
		  
		 }
		 if(!strcmp(argv[1],"-s"))//�ݹ�Ŀ¼�·����������ļ�
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

	//���㵥����
    int countWord(char *file)
	{
		FILE *fp;
		int wCount=0;
		int is_word=0;
		char a;
		fp=fopen(file,"r");
		if(fp==NULL){
		  printf("�ļ���ʧ��\n");
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
		printf("���ļ�������Ϊ��%d\n",wCount);
		return wCount;
	}
	//�����ַ���
	int countChar(char *file)
	{
		FILE *fp;
		fp=fopen(file,"r");
		char a;
		int cCount=0;
		if(NULL==fp)
		{
		  printf("�ļ�Ϊ��\n");
		}else{
			while((a=fgetc(fp))!=EOF){
				  cCount++;
			}
		}
	  fclose(fp);
	   printf("�ַ���Ϊ:%d\n",cCount);
	   return cCount;
	}
	//��������
	int countLine(char *file)
	{
		FILE *fp;
		fp=fopen(file,"r");
		int lCount=0;
		char a;
		if(NULL==fp)
		{
		  printf("�ļ�Ϊ��\n");
		}else{
			while((a=fgetc(fp))!=EOF){
			  if(a=='\n')
				  lCount++;
			}
		}
		fclose(fp);
	   printf("�ļ�������Ϊ��%d\n",lCount); 
	   return lCount;
	}
	//����
    int count_blankLine(char *file)
	{
	   FILE *f;
      int blCount= 0;
      int ch_num = 0;
      char ch;
      f = fopen(file, "r");
       if(NULL==(f=fopen(file,"r")))
	   {
       printf("�ļ�Ϊ��");
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
	   printf("�ļ�����Ϊ:%d\n ",blCount);
	   return blCount;
	}
	//������
	int count_codeLine(char *file)
	{   
		FILE *fp;
		fp=fopen(file,"r");
		int clCount=0;
		char a;
		if(NULL==fp)
		{
		  printf("�ļ�Ϊ��\n");
		}else{
			while((a=fgetc(fp))!=EOF){
				 if(a==';')
					 clCount++;	  
			}
		}
		fclose(fp);
	   printf("�ļ���������Ϊ��%d\n",clCount);  
	   return clCount;
	}
	//ע����
    int count_noteLine(char *file)
	{
	    FILE *f;
        int ch_num = 0;
		int nlCount=0;
        char ch;
        f=fopen(file, "r");
        if(NULL==(f=fopen(file,"r")))
		{
         printf("�ļ�Ϊ��\n");
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
       printf("�ļ�ע����Ϊ:%d\n ",nlCount);
	   return nlCount;
	}
	//�ݹ��ҷ����������ļ�
   void Scan(char *Path, char Type) {
	char *FileName = NULL;
	char *FileType = NULL;
	char Temp[30];	//�����ݴ�ı���ַ���
	long Head;
	struct _finddata_t FileData;
	int i = 0;

	FileName = Path;
	while (*(Path + i) != '\0') {	//�ҳ��ļ������ļ����͵�λ��
		if (*(Path + i) == '\\')
			FileName = Path + i + 1;
		if (*(Path + i) == '.')
			FileType = Path + i + 1;
		i++;
	}
	
	strcpy(Temp, FileType);//�����ַ���
	*FileType = '*';
	*(FileType + 1) = '\0';
	
	Head = _findfirst(Path, &FileData);
	
	strcpy(FileType, Temp);//�ָ��ַ���

	do {
		if ( !strcmp(FileData.name, "..") || !strcmp(FileData.name, "."))	//ȥ��ǰ���ļ�·��
			continue;
		
		if (_A_SUBDIR == FileData.attrib)	//���ļ���
		{	
			strcpy(Temp, FileName);	//�����ַ���
			for (i = 0; *(FileData.name + i) != '\0'; i++) {
				*(FileName + i) = *(FileData.name + i);
			}
			*(FileName + i) = '\\';
			*(FileName + i + 1) = '\0';
			strcat(Path, Temp);

			Scan(Path, Type);

			strcpy(FileName, Temp);	//�ָ��ַ���			
		}
		else//���ļ� 
		{	
			for (i = 0; *(FileData.name + i) != '.'; i++);
			if (!strcmp(FileData.name + i + 1, FileType)) {	//��ָ�����͵��ļ�
				
				strcpy(Temp, FileName);
				strcpy(FileName, FileData.name); //�����ַ���
				
			printf("%s:  ", FileData.name);
				//Run(Type, NULL, Path);	//����ַ�����ܴ�����������
				printf("\n");

				strcpy(FileName, Temp);//�ָ��ַ���
			}
		}
	} while (_findnext(Head, &FileData) == 0);

	_findclose(Head);	
}
	void printFile(char *file,int result,char type){
	  FILE *wp;
	  if((wp=fopen("outputFile.txt","a"))==NULL){
		   printf("�ļ�������\n\n");
	  }else{
		  switch(type){
		  case 'c':
			      fprintf(wp, "%s�ļ����ַ�����%d", file,result);
			        break;
		  case 'w':fscanf(wp, "%s�ļ��е�������%d", file,result);
			       fprintf(wp, "%s�ļ��е�������%d", file,result);
			       break;
		  case 'l':
			       fprintf(wp, "%s�ļ�������������%d", file,result);
			       break;
		  case 'f':
			       fprintf(wp, "%s�ļ��д���������%d", file,result);
				   break;
		  case 'e':
			      fprintf(wp, "%s�ļ��п�������%d", file,result);
				  break;
		  case 'g':
			       fprintf(wp, "%s�ļ���ע������%d", file,result);break;
		  default:; break;
		  }   
	  }
     fclose(wp);
	}

	