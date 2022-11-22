package data.dataSource.local;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class DB {
    private static DB single_instance = null;

    private DB() {
    }

    public static DB I() {
        if (single_instance == null)
            single_instance = new DB();

        return single_instance;
    }

    private List<Map<String, Object>> db = new ArrayList<Map<String, Object>>();

    public List<Map<String, Object>> getDB() {
        return db;
    }

    public void addDB(Map<String, Object> user) {
        db.add(user);
    }

    public void removeDB(String userID) {
        int id = 0;
        int index = 0;
        for (Map<String, Object> user : db) {
            if (user.get("email") == userID) {
                id = index;
                break;
            }
            index++;
        }
        db.remove(id);
    }

    public void updateDB(Map<String, Object> user) {
        int id = 0;
        int index = 0;
        for (Map<String, Object> userDB : db) {
            if (userDB.get("email") == user.get("email") && userDB.get("password") == user.get("password")) {
                id = index;
                break;
            }
            index++;
        }
        Map<String, Object> findedUser = db.get(id);
        findedUser.replace("email", user.get("email"));
        findedUser.replace("password", user.get("password"));
        findedUser.replace("name", user.get("name"));
        findedUser.replace("emails", user.get("emails"));
    }
}
