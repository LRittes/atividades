package data.DTO;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import domain.entity.Email;
import domain.entity.User;
import utils.FunctionsUtil;

public class UserDTO {

    public static User fromJson(Map<String, Object> user) {
        List<Email> list = new ArrayList<>();
        list = (List<Email>) FunctionsUtil.convertObjectToList(user.get("emails"));

        User userRet = new User(user.get("name").toString(), user.get("password").toString(),
                user.get("email").toString(),
                list);

        return userRet;
    }

    public static Map<String, Object> toJson(User user) {
        Map<String, Object> userMap = new HashMap<>();

        userMap.put("name", user.getName());
        userMap.put("password", user.getPassword());
        userMap.put("email", user.getEmail());
        userMap.put("emails", user.getEmails());

        return userMap;
    }
}
