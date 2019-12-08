#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int myAtoi(string str) {
		long long res = 0;
		int sign = 1;
		int i = 0;
		while (str[i] == ' ') ++i;
		if (str[i] >= '0' && str[i] <= '9')
		{
			res += 10 * res + str[i] - '0';
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			sign = (str[i] == '+') ? 1 : -1;
		}
		else
		{
			return 0;
		}
		while (++i < str.size() && str[i] >= '0' && str[i] <= '9')
		{
			res = 10 * res + str[i] - '0';
			if (sign == 1 && res >= INT_MAX)
				return INT_MAX;
			if (sign == -1 && res * -1 <= INT_MIN)
				return INT_MIN;
		}
		return sign * res;
	}
};