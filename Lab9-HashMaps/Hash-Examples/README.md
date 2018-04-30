# HashDetails
We have talked about hashing integers, but what about if you have a string or a complex data structure?  With a little type casting, we can compute a hash for any data structure.

Lets take a look at an example hashing function
```c++
template <typename T>
int hashme(T param, int tablesize) {
    unsigned char *ptr = (unsigned char *)&param;
    int sum = 0;
    for(int i = 0; i < sizeof(param); i++) {
        sum += ptr[i];
    }
    int hashval = sum%tablesize;
    cout << "Size = "<<sizeof(param)<<" Sum = "<<sum<<" hash "<<hashval<<endl;
    return hashval;
}
```
* We declare this as a template function so it can be applied to any data structure.  
* We use typecasting to point ptr at the address of the parameter.  ptr can then look at the data structure one byte at a time.
* The sizeof() function will return the number of bytes (or unsigned characters) in the parameter.
* We can use this size to compute a sum of all the bytes in the parameter.
* The function then uses the mod operator to return a hash between 0 and the tablesize

You can then call the hash function with whatever type you want to hash.
```c++
    string foo("Hello");
    cout << "Hash of Hello "<<hashme<string>(foo, tablesize)<<endl;
```
Although this hash function works well for arrays and strings, you would have to write a more complex hashing function for a vector since it will allocate memory on the heap.  But this hash function may still spread out the values based on the internal structure of the vector.
