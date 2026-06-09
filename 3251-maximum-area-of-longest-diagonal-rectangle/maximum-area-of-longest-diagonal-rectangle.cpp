class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long max_diagonal_sq = 0;
        int max_area = 0;

        for (const auto& dim : dimensions) {
            long long l = dim[0];
            long long w = dim[1];

            long long diagonal_sq = l * l + w * w;
            int area = l * w;

            if (diagonal_sq > max_diagonal_sq) {
                max_diagonal_sq = diagonal_sq;
                max_area = area;
            } else if (diagonal_sq == max_diagonal_sq) {
                max_area = std::max(max_area, area);
            }
        }

        return max_area;
    }
};
        
    