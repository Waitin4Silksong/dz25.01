#include <cstring>
#include <iostream>
#include <string>
#pragma warning(disable : 4996)
// operator >= -- 212
// operator <= -- 232
// operator + -- 258
// resize() -- 111
// push_front(char) -- 48
// push_front(const char*) -- 91

class Str {
private:
	char* text;
	int size;
public:
	Str() : text{ nullptr }, size{ 0 } {}
	Str(const char* text)
	{
		this->size = strlen(text);
		this->text = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->text[i] = text[i];
		}
		this->text[size] = '\0';
	}
	Str(const Str& str)
	{
		this->size = str.size;
		this->text = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			text[i] = str.text[i];
		}
	}
	void push_back(char c)
	{
		char* tmp = new char[size + 1];
		strncpy(tmp, text, size);
		tmp[size] = c;
		size++;

		delete[] text;
		text = tmp;
		tmp = nullptr;
	}
	void push_front(char c)
	{
		char* tmp = new char[size + 2];
		strncpy(tmp + 1, text, size);
		tmp[0] = c;
		tmp[size + 1] = '\0';
		size++;

		delete[] text;
		text = tmp;
		tmp = nullptr;
	}
	void append(int space, char value)
	{
		char* tmp = new char[size + 2];
		strncpy(tmp, text, size);
		char last = tmp[size - 1];
		for (int i = space; i < size; i++)
		{
			tmp[i + 1] = tmp[i];
		}
		tmp[space] = value;
		tmp[size] = last;
		tmp[size + 1] = '\0';
		size++;

		delete[] text;
		text = tmp;
		tmp = nullptr;
	}
	void push_back(const char* c)
	{
		int NEWsize = size + strlen(c);
		char* tmp = new char[NEWsize + 1];
		strncpy(tmp, text, size);
		strncpy(tmp + size, c, NEWsize - size);
		tmp[NEWsize] = '\0';
		size = NEWsize;

		delete[] text;
		text = tmp;
		tmp = nullptr;
	}
	void push_front(const char* c)
	{
		int NEWsize = size + strlen(c);
		char* tmp = new char[NEWsize + 1];
		strncpy(tmp, c, strlen(c));
		strncpy(tmp + strlen(c), text, size);
		tmp[NEWsize] = '\0';
		size = NEWsize;

		delete[] text;
		text = tmp;
		tmp = nullptr;
	}
	void replace(int start, int end, const char* value)
	{
		for (int i = start; i <= end; i++)
		{
			text[i] = *value;
		}
	}
	void resize(int newsize) // used here GPT lil bit
	{
		if (size < 0)
		{
			std::cout << "Invalid input.";
		}
		else
		{
			char* tmp = new char[newsize + 1];
			int sizesize = newsize > size ? newsize : size;
			strncpy(tmp, text, sizesize);
			for (size_t i = sizesize; i < newsize; i++)
			{
				tmp[i] = '\0';
			}
			tmp[newsize] = '\0';
			size = newsize;

			delete[] text;
			text = tmp;
			tmp = nullptr;
		}
	}

	friend std::ostream& operator << (std::ostream& out, const Str& text)
	{
		out << text.text;
		return out;
	}
	friend std::istream& operator >> (std::istream& in, Str& str)
	{
		str.clear();
		char* tmp = new char[10000];
		in.getline(tmp, 10000);
		str.push_back(tmp);
		return in;
	}
	bool operator==(const Str& str)const
	{
		if (size != str.size)
		{
			return false;
		}
		for (int i = 0; i < size; i++)
		{
			if (text[i] != str.text[i])
			{
				return false;
			}
		}
		return true;
	}
	friend bool operator>(const Str& LeftStr, const Str& rightStr)
	{
		if (rightStr == LeftStr)
		{
			return false;
		}

		int size = LeftStr.size > rightStr.size ? rightStr.size : LeftStr.size;
		int numberLeft = 0;
		int numberRight = 0;

		for (int i = 0; i < size; i++)
		{
			if (LeftStr.text[i] > rightStr.text[i])
			{
				numberLeft++;
			}
			if (LeftStr.text[i] < rightStr.text[i])
			{
				numberRight++;
			}
		}
		return numberLeft > numberRight;

	}
	friend bool operator<(const Str& LeftStr, const Str& rightStr)
	{
		if (rightStr == LeftStr)
		{
			return false;
		}

		int size = LeftStr.size > rightStr.size ? rightStr.size : LeftStr.size;
		int numberLeft = 0;
		int numberRight = 0;

		for (int i = 0; i < size; i++)
		{
			if (LeftStr.text[i] < rightStr.text[i])
			{
				numberLeft++;
			}
			if (LeftStr.text[i] > rightStr.text[i])
			{
				numberRight++;
			}
		}
		return numberLeft > numberRight;
	}
	friend bool operator>=(const Str& LeftStr, const Str& rightStr)
	{
		int size = LeftStr.size > rightStr.size ? rightStr.size : LeftStr.size;
		int numberLeft = 0;
		int numberRight = 0;

		for (int i = 0; i < size; i++)
		{
			if (LeftStr.text[i] > rightStr.text[i])
			{
				numberLeft++;
			}
			
			if (LeftStr.text[i] < rightStr.text[i])
			{
				numberRight++;
			}
		}
		return numberLeft >= numberRight;
	} 
	friend bool operator<=(const Str& LeftStr, const Str& rightStr)
	{
		int size = LeftStr.size > rightStr.size ? rightStr.size : LeftStr.size;
		int numberLeft = 0;
		int numberRight = 0;

		for (int i = 0; i < size; i++)
		{
			if (LeftStr.text[i] > rightStr.text[i])
			{
				numberLeft++;
			}

			if (LeftStr.text[i] < rightStr.text[i])
			{
				numberRight++;
			}
		}
		return numberLeft <= numberRight;
	}
	Str operator+(const Str& strLeft)
	{
		Str result(text);
		result.push_back(strLeft.text);
		return result;
	}
	friend Str operator+(const char* strLeft, const Str& strRight)
	{
		Str result(strLeft);
		result.push_back(strRight.text);
		return result;
	}
	void clear()
	{
		delete[] text;
		text = nullptr;
		size = 0;
	}
	~Str() { clear(); }
};



int main()
{
	Str s1 = "ZZZ";
	Str s2 = "AAAA";
	Str s3 = "AAAA";
	Str s4 = "World!";
	std::string s12 = "ZZZ";
	std::string s22 = "AAAA";

	std::cout << (s1 > s2);
	std::cout << std::endl;
	std::cout << (s1 >= s3);
	std::cout << std::endl;
	std::cout << (s2 >= s3);
	std::cout << std::endl;
	std::cout << (s2 >= s1);
	std::cout << std::endl;
	std::cout << "Hello " + s4;
}