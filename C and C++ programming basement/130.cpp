void expand (char *s ,char *t)
{int i =0, j=0;
   for(;s[i] !='\0';i++,j++)
      switch(s[i]){
	  case'\n': t[j] = '\\' ;
		          t[++j] ='n';
				  break;
	  case'\t': t[j] ='\\';
		          t[++j] ='t';
				  break;
		default: t[j] = s[i];
		          break;
	  }
	  t[j] ='\0';
}