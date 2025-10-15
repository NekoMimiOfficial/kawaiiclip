#include <filesystem>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

string EMOTICONS_FILE= "/etc/kawaiiclip/emoticons.txt";

int select_emoticon(vector<string> emoticons, size_t index)
{
  string selected_emoticon;
  size_t count= emoticons.size();

  if (count < 1)
  {return 7;}

  if (index > 1 && index < count)
  {
    selected_emoticon= emoticons[index - 1];
    string cmd= "echo \""+ selected_emoticon+ "\" | wl-copy";
    return system(cmd.c_str());
  } else
  {
    return 101;
  }
}

bool chk_root()
{return (geteuid() == 0);}

bool chk_user_list()
{
  string home= getenv("HOME");
  string user_file= home+ "/.config/kawaiiclip/emoticons.txt";

  return filesystem::exists(user_file);
}

vector<string> get_emoticons()
{
  string base;
  if (chk_user_list())
  {
    base= getenv("HOME");
    base= base+ "/.config/kawaiiclip/emoticons.txt";
  } else
  {base= EMOTICONS_FILE;}
  cout << "Using DB: " << base << "\n\n";

  if (!(filesystem::exists(EMOTICONS_FILE)))
  {
    vector<string> vec;
    return vec;
  } else
  {
    ifstream input_file_stream;
    input_file_stream.open(base);
    vector<string> vec;
    string line;

    while (getline(input_file_stream, line))
    {vec.push_back(line);}

    return vec;
  }
}

int main(int argc, char* argv[])
{
  cout << "KawaiiClip\n";
  cout << "~~~~~~~~~~\n";

  vector<string> list_of_emoticons= get_emoticons();

  bool predefined= false;
  int pre_index= 0;
  int ret= 0;

  for (int i= 1; i< argc; i++)
  {
    std::string arg = argv[i];
    if (arg == "-n" && (i+ 1)<= argc)
    {predefined= true; pre_index= (int)* argv[i+ 1];}
  }

  size_t selected_i;
  if (predefined)
  {ret= select_emoticon(list_of_emoticons, pre_index);cout << "selecting ID: " << pre_index << "\n";}

  size_t list_index= 1;
  for (string element: list_of_emoticons)
  {cout << "[" << list_index << "] " << list_of_emoticons[list_index- 1] << "\n"; list_index++;}

  if (list_of_emoticons.size() < 1)
  {
    cout << "Empty list of emoticons.\n"
         << "Add new entries by editing either of these files:\n\n"
         << "/etc/kawaiiclip/emoticons.txt\n"
         << "~/.config/kawaiiclip/emoticons.txt\n";
    return 7;
  }

  int e_choice;
  cout << "Select an emoticon > ";
  cin >> e_choice;

  ret= select_emoticon(list_of_emoticons, e_choice);

  return ret;
}
