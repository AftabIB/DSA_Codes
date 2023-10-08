class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();  // Size of the gas and cost vectors
        int deficit = 0;  // Total deficit in gas
        int start = 0;  // Starting index of the possible circuit
        int balance = 0;  // Current gas balance

        for (int i = 0; i < n; i++) {
            balance += gas[i] - cost[i];  // Calculate the balance at the i-th station

            // If balance is negative, update the start and reset the balance
            if (balance < 0) {
                deficit += balance;  // Accumulate the deficit
                start = i + 1;  // Update the start to the next station
                balance = 0;  // Reset the balance
            }
        }

        // If deficit plus the final balance is non-negative, a circuit is possible
        if (deficit + balance >= 0) {
            return start;  // Return the starting index of the possible circuit
        } else {
            return -1;  // No possible circuit found
        }
    }
};
