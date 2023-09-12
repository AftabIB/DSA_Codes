import java.util.*;

class AuthenticationManager {
    private final Map<String, Integer> tokens;
    private final TreeMap<Integer, String> timestamps;
    private int timeToLive;

    public AuthenticationManager(int timeToLive) {
        this.timeToLive = timeToLive;
        this.tokens = new HashMap<>();
        this.timestamps = new TreeMap<>();
    }

    public void generate(String tokenId, int currentTime) {
        removeExpiredTokens(currentTime);
        tokens.put(tokenId, currentTime + timeToLive);
        timestamps.put(currentTime + timeToLive, tokenId);
    }

    public void renew(String tokenId, int currentTime) {
        if (tokens.containsKey(tokenId)) {
            int expirationTime = tokens.get(tokenId);
            if (expirationTime > currentTime) {
                timestamps.remove(expirationTime);
                tokens.put(tokenId, currentTime + timeToLive);
                timestamps.put(currentTime + timeToLive, tokenId);
            }
        }
    }

    public int countUnexpiredTokens(int currentTime) {
        removeExpiredTokens(currentTime);
        return tokens.size();
    }

    private void removeExpiredTokens(int currentTime) {
        while (!timestamps.isEmpty()) {
            Map.Entry<Integer, String> entry = timestamps.firstEntry();
            int expirationTime = entry.getKey();
            if (expirationTime <= currentTime) {
                String tokenId = entry.getValue();
                timestamps.pollFirstEntry();
                tokens.remove(tokenId);
            } else {
                break;
            }
        }
    }
}
