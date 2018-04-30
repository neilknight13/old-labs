vector<string> tokens { istream_iterator<string>(iss), istream_iterator<string>{} };

for (auto &s : tokens) {
   ostringstream contextstream;
   model[context].push_back(s);
   context = s;
}

cout << "make text...";
context = initialcontext;
ostringstream oss;
string next;
//genLength is used to prevent infinite loop and regulate size of text desired.
for (auto i = 0; i < genLength; i++) {
   next = model[context][rand() % model[context].size()];
   context = next; ///word just generated will be the new context;
   oss << next << " ";
}

return oss.str();