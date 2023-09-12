import java.util.*;

class AuthenticationManager {
    private final TreeMap<Integer, String> timestamps;
    private final Map<String, Integer> tokens;
    private final int timeToLive;

    public AuthenticationManager(final int timeToLive) {
        this.timestamps = new TreeMap<>();
        this.tokens = new HashMap<>();
        this.timeToLive = timeToLive;
    }

    public void generate(final String tokenId, final int currentTime) {
        removeExpiredTokens(currentTime);
        tokens.put(tokenId, currentTime);
        timestamps.put(currentTime, tokenId);
    }

    public void renew(final String tokenId, final int currentTime) {
        removeExpiredTokens(currentTime);
        if (tokens.containsKey(tokenId)) {
            int tokenTime = tokens.get(tokenId);
            if (currentTime - tokenTime < timeToLive) {
                timestamps.remove(tokenTime);
                timestamps.put(currentTime, tokenId);
                tokens.put(tokenId, currentTime);
            }
        }
    }

    public int countUnexpiredTokens(final int currentTime) {
        removeExpiredTokens(currentTime);
        return tokens.size();
    }
    
    private void removeExpiredTokens(final int currentTime) {
        final Iterator<Map.Entry<Integer, String>> iterator = timestamps.entrySet().iterator();
        while (iterator.hasNext()) {
            Map.Entry<Integer, String> entry = iterator.next();
            int tokenTime = entry.getKey();
            if (currentTime - tokenTime >= timeToLive) {
                String tokenId = entry.getValue();
                iterator.remove();
                tokens.remove(tokenId);
            } else {
                break;
            }
        }
    }
}