#include <iostream>
#include<cstring>
#include<string>
#include <fstream>
#include<cstdlib>

using namespace std;

class phone_dir
{
  public:
    string fname;
    string lname;
    string phoneno;
    string no;
    int location;
  public:
    void setfname(string fn);
    void setlname(string ln);
    void setphoneno(string phn);
    //void setno(string phn);
    string  getFname( );
	string getLname( );
	string getphoneno( );
	//string getno();
};
/*string phone_dir::getno()
{
   return no;
}
void phone_dir::setno(string phn)
{
    no = phn;
}*/
void phone_dir::setfname(string fn)
{
    fname = fn;
}
void phone_dir::setlname(string ln)
{
    lname = ln;
}
void phone_dir::setphoneno(string phn)
{
    phoneno = phn;
}

string phone_dir::getFname()
{
   return fname;
}

string phone_dir::getLname()
{
   return lname;
}

string phone_dir::getphoneno()
{
   return phoneno;
}


phone_dir pdir[5000];
phone_dir p[5000];
int dir = 0;
int tmp_dir = 0;
void converttoupper (string& s)
{
    int i;
    for (i = 0;i < s.length();i++)
    {
        s[i] = toupper(s[i]);
    }
    //return s;
}
void printresult(phone_dir *p)
{
    int i;
    for (i = 0 ; i < dir; i++)
    {
        cout<<i+1<<". "<<p[i].getFname()<<" "<<p[i].getLname()<<", "<<p[i].no<<endl;
    }

}

void merge(int l, int m, int r,phone_dir *p)
{
	int k = l;
	phone_dir p1[dir];
	phone_dir p2[dir];
	int i=l;
	int j=m+1;
     for (; i <= m; i++)
     {
       p1[i] = p[i];
     }

     for (; j <= r; j++)
     {
       p2[j] = p[j];
     }
	i=l;
	j= m + 1;
    for (;i <= m && j <= r;)
     {
        string lname1 = p1[i].getLname();
        converttoupper(lname1);
        string lname2 = p2[j].getLname();
        converttoupper(lname2);
        string fname1 = p1[i].getFname();
        converttoupper(fname1);
        string fname2 = p2[j].getFname();
        converttoupper(fname2);
        if (lname1 == lname2)
       {
           if (fname1 <= fname2)

           {
                p[k] = p1[i];
                i++;
            }
            else
            {
                p[k] = p2[j];
                j++;
            }
            k++;
       }
        else
        {
        if (lname1 < lname2)
           {
                p[k] = p1[i];
                i++;
            }
            else
            {
                p[k] = p2[j];
                j++;
            }
            k++;
     }

     }

     for (;i <= m || j <= m;) {
        if (i <= j)
            {
            p[k] = p1[i];
            k++;
            i++;
        }
        else
        {
            p[k] = p2[j];
            k++;
            j++;
        }
     }


}
void mergesort(int start, int end,phone_dir *p)
    {
        if (start < end)
        {
            int middle = (start+end)/2;
            mergesort( start, middle,p);
            mergesort( middle+1, end,p);
            merge(start, middle, end,p);
        }
    }
int index (int start_index,int end_index,phone_dir *p)
{
    int rand_no=start_index + rand()%(end_index-start_index);
    if (rand_no != start_index)
    {
        phone_dir temp[1] = p[rand_no];
        p[rand_no] = p[start_index];
        p[start_index] = temp[0];
    }
    phone_dir pivot[1] = p[start_index];
    int left = start_index + 1;
    int right = end_index;
    int loop_flag = 1;
    for(;loop_flag=1;)
    {
        while (pivot[0].getphoneno() > p[left].getphoneno() && left <= right)
        {
            left++;
        }
        while ((pivot[0].getphoneno() < p[right].getphoneno()) && right >= start_index && right <= end_index)
        {
            right--;
        }
        if(left<right)
        {
            phone_dir temp1[1]=p[left];
            p[left] = p[right];
            p[right] = temp1[0];
        }
        else{
            p[start_index] = p[right];
            p[right] =  pivot[0];
            break;
        }

    }
return right;
}
void randomQuickSort(int start_index,int end_index,phone_dir *p)
{
    if (start_index < end_index)
    {
        int find_index;
        find_index = index(start_index,end_index,pdir);
        randomQuickSort(start_index,find_index-1,pdir);
        randomQuickSort(find_index+1,end_index,pdir);
    }
}
void sortDirectory()
{

    mergesort(0,dir-1,pdir);

    //randomQuickSort(4,5,pdir);
    int prev_match_cnt = 0;
    int start_index = 0;
    int end_index = 0;
    string prev_name;
    string prev_lname;
    string comp_name;
    string comp_last_name;
	int loop_cnt = 0;
    int i;

	for (i=0;i<dir;i++)
    {
        comp_name = pdir[i].getFname();
        converttoupper(comp_name);
        comp_last_name = pdir[i].getLname();
        converttoupper(comp_last_name);
        if (comp_name == prev_name && comp_last_name == prev_lname)
        {
            prev_match_cnt = 1;
            if (start_index == 0)
            {
               start_index = i-1;
               end_index = i;
            }
            else
            {
                end_index = i;
            }
        }
        else{
                if (end_index > 0)
                {
                   randomQuickSort(start_index,end_index,pdir);
                }
                prev_match_cnt = 0;
            start_index = 0;
            end_index = 0;
            prev_name = "";
            prev_lname = "";
        }
                if (end_index > 0)
                {
                   randomQuickSort(start_index,end_index,pdir);
                }
        if (prev_match_cnt == 0)
        {
             //loop_cnt = 1;
             prev_name = pdir[i].getFname();
             converttoupper(prev_name);
             prev_lname = pdir[i].getLname();
             converttoupper(prev_lname);
        }
    }
    }


bool complnamefname(string lname, string fname,string lname1,string fname1)
{
    if(lname<lname1)
    {
        return true;
    }
    else if(lname>lname1)
    {
       return false;
    }
    else
    {
        if(fname<fname1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int Binarysearch (string fname,string lname,int f,int l)
{
    if (f <= l) {
       int mid = (f + l) / 2;  // compute mid point.
       string fname1 = pdir[mid].fname;
       converttoupper(fname1);
       string lname1 = pdir[mid].lname;
       converttoupper(lname1);
       if (fname == fname1 && lname == lname1)
       {
           //cout<<"found"<<endl;
           tmp_dir = 0;
           //phone_dir p[1000];
           p[tmp_dir].fname = pdir[mid].fname;
           p[tmp_dir].lname = pdir[mid].lname;
           p[tmp_dir].no = pdir[mid].no;
           p[tmp_dir].location = mid + 1;
           tmp_dir = tmp_dir + 1;
           int search_index = mid;
           int loop_flag = 1;
           int i = 1;
           if (mid != 0)
           {
           while (loop_flag==1)
           {
               fname1 = pdir[search_index-i].fname;
               converttoupper(fname1);
               lname1 = pdir[search_index-i].lname;
               converttoupper(lname1);
               if (fname == fname1 && lname == lname1)
               {
                p[tmp_dir].fname = pdir[search_index-i].fname;
                p[tmp_dir].lname = pdir[search_index-i].lname;
                p[tmp_dir].no = pdir[search_index-i].no;
                p[tmp_dir].location = search_index-i +1;
                tmp_dir = tmp_dir + 1;
                i = i + 1;
               }
               else
               {
                   break;
               }
           }
           }
           i = 1;
           if(mid != dir -1)
           {
            while (loop_flag==1)
           {
               fname1 = pdir[search_index+i].fname;
               converttoupper(fname1);
               lname1 = pdir[search_index+i].lname;
               converttoupper(lname1);
               if (fname == fname1 && lname == lname1)
               {
                p[tmp_dir].fname = pdir[search_index+i].fname;
                p[tmp_dir].lname = pdir[search_index+i].lname;
                 p[tmp_dir].no = pdir[search_index+i].no;
                 p[tmp_dir].location = search_index+i+1;
                tmp_dir = tmp_dir + 1;
                i = i + 1;
               }
               else
               {
                   break;
               }
           }
           }
       return 0;
       }
       else if (complnamefname(lname,fname,lname1,fname1) == true)

           Binarysearch(fname,lname, f, mid-1);
       else

           Binarysearch(fname,lname, mid+1, l);
   }
   return 0;
}
void searchDirectory(char* name)
{
   int first = 0;
   int last = dir - 1;
   string fname = "";
   string lname = "";
   cout << "Please enter the Name:\n";
   //getline(cin, fname);
   cin>>fname>>lname;
   converttoupper(fname);
   //cout << "Please enter Last Name:\n";
   //getline(cin, lname);
   converttoupper(lname);
   int j = Binarysearch(fname,lname,first,last);
   if (tmp_dir > 0)
   {
      int i;
    for (i = 0 ; i < tmp_dir; i++)
    {
        cout<<p[i].location<<". "<<p[i].getFname()<<" "<<p[i].getLname()<<", "<<p[i].no<<endl;
    }
    tmp_dir = 0;
   }
   else
   {
       cout<<"Name not found"<<endl;
   }
}
void insertEntry(char* name,char* phone_number)
{
   string fname = "";
   string lname = "";
   string phone = "";
   cout << "Please enter the Name:\n";
   //getline(cin, fname);
   cin>>fname>>lname;
   cout << "Please enter the Phone Number:\n";
   cin>>phone;
   //converttoupper(fname);
   //cout << "Please enter Last Name:\n";
   //getline(cin, lname);
   string fname2 = fname;
   converttoupper(fname);
   string lname2 = lname;
   converttoupper(lname);
   //converttoupper(phone);
   //getline(cin, phone);
   string phone2 = phone;
   string phone3 = phone;
   phone3.erase(0,1);
   phone3.erase(3,1);
   phone3.erase(6,1);
   phone.erase(0,1);
   phone.erase(3,1);
   phone.erase(6,1);
   char c1[phone.length()];
	strcpy(c1, phone.c_str());
	int n1 = atoi(c1);
   int i;
   int dir_match = 0;
   for (i = 0 ; i < dir; i++)
    {
    string fname1 = pdir[i].getFname();
    string lname1 = pdir[i].getLname();
    string phone1= pdir[i].getphoneno();
    converttoupper(fname1);
    converttoupper(lname1);
	char c[phone1.length()];
	strcpy(c, phone1.c_str());
	int n = atoi(c);

	/*if(phone1[0] == "(") {
		phone1 = phone1.erase(0,1);
		phone1 = phone1.erase(3,4);
		phone1 = phone1.erase(6,7);
	}*/
   // converttoupper(phone1);
    //phone1.erase(0,1);
    //phone1.erase(3,1);
    //phone1.erase(6,1);
    if ((fname == fname1) && (lname == lname1) && (n==n1))
    {
       dir_match = 1;
       break;
    }
    }
    if (dir_match == 0)
    {
       pdir[dir].setfname(fname2);
       pdir[dir].setlname(lname2);
       pdir[dir].setphoneno(phone3);
       pdir[dir].no = phone2;
       dir = dir + 1;
       sortDirectory();
    }
    else
    {
        cout<<"Entry already exist in the Directory"<<endl;
    }
}
void deleteEntry(char* name)
{
    string fname = "";
   string lname = "";
   string phone = "";
   cout << "Please enter the Name:\n";
   cin>>fname>>lname;
   //getline(cin, fname);
   converttoupper(fname);
   //cout << "Please enter Last Name:\n";
   //getline(cin, lname);
   converttoupper(lname);
    int i = dir-1;
    int dir_match = 0;
    for(i;i>=0;i--)
    {
    string fname1 = pdir[i].getFname();
    string lname1 = pdir[i].getLname();
    converttoupper(fname1);
    converttoupper(lname1);
    if (fname == fname1 && lname == lname1)
    {
       dir_match = 1;
       break;
    }
    }
    if (dir_match == 1)
    {
        int j =dir -1;
       for(i;i<j;i++)
       {
           pdir[i] = pdir[i+1];
       }
       pdir[dir-1].setfname("");
        pdir[dir-1].setlname("");
        pdir[dir-1].setphoneno("");
       dir = dir - 1;
    }
    else
    {
        cout<<"Unable to delete as entry not found"<<endl;
    }
}

void create(char* filename)
{
string line;
	ifstream file(filename);
	//char* filename = filename;
    //file.open("input.csv");

        while(!file.eof()) // To get you all the lines.
        {
	        getline(file,line); // Saves the line in STRING.
	        //cout<<line<<endl; // Prints our STRING.
            int n = line.length();
            char split[n+1];
            strcpy(split,line.c_str());
            char * pch;
            pch = strtok (split," ,");
            int line_cnt = 0;
            while (pch != NULL)
                {

                if (line_cnt == 1)
                {
                     // printf ("%s\n",pch);
                      string s(pch);
                      //cout << "s:"<<s <<endl;
                      pdir[dir].setfname(s);
                }

                if (line_cnt == 2)
                {
                   //   printf ("%s\n",pch);
                      string s2(pch);
                      //cout <<"s1:"<< s2 <<endl;
                      pdir[dir].setlname(s2);
                }
                if (line_cnt == 3)
                {
                     // printf ("%s\n",pch);
                      string s1(pch);
                      pdir[dir].no = s1;
					  s1.erase(0,1);
					s1.erase(3,1);
					s1.erase(6,1);
                      pdir[dir].setphoneno(s1);
                      dir = dir + 1;
                      /*s1.erase(0,1);
                       s1.erase(3,1);
                       s1.erase(6,1);*/
                      //pdir[dir].setno(s1);
                }
                pch = strtok (NULL, " ,");
                line_cnt = line_cnt +1;
                }


        }
        file.close();
        sortDirectory();
}
int main(int argc, char *argv[])
{
    int choice;
	//cout<<"Hello world"<<endl;
    char *file1 = argv[1];//"input.csv";
    char* name;
    char* phone_number;
    create(file1);
    while(1)
    {
    cout<<"Please provide options:"<<endl<<"Insert (Press 1)"<<endl<<"Search (Press 2)"<<endl<<"Delete (Press 3)"<<endl<<"Show Directory (Press 4)"<<endl<<"Exit (Press 5)"<<endl;
    cin>>choice;
    switch(choice)
    {
    case 2:
	searchDirectory(name);
	cout<<""<<endl;
	break;
    case 1:
	insertEntry(name, phone_number);
	cout<<""<<endl;
	break;
    case 3:
	deleteEntry(name);
	cout<<""<<endl;
	break;
    case 4:
    printresult(pdir);
    cout<<""<<endl;
    break;
    case 5:
         exit(0);
    default:
    cout<<"Invalid option selected"<<endl;
    break;
    }
    }
    return 0;
}
