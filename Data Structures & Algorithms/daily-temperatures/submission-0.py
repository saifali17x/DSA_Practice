class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:

        res = []
        n = len(temperatures)

        for i in range(n):
            j = i + 1
            count = 1

            while j < n:
                if temperatures[j] > temperatures[i]:
                    break

                j += 1
                count += 1

            if j == n:
                count = 0

            else:
                count
            res.append(count)
        return res
                    


            