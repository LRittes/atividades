package data.DTO;

import java.util.HashMap;
import java.util.Map;

import domain.entity.Email;

public class EmailDTO {

    public EmailDTO() {
    }

    public static Email fromJson(Map<String, Object> email) {
        int id = Integer.parseInt(email.get("id").toString());

        Email emailRet = new Email(id, email.get("author").toString(), email.get("receiver").toString(),
                email.get("message").toString());

        return emailRet;
    }

    public static Map<String, Object> toJson(Email email) {
        Map<String, Object> emailMap = new HashMap<>();

        emailMap.put("author", email.getAuthor());
        emailMap.put("receiver", email.getReceiver());
        emailMap.put("message", email.getMessage());
        emailMap.put("id", email.getId());

        return emailMap;
    }
}