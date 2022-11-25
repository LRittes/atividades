package data.DTO;

import java.util.HashMap;
import java.util.Map;

import domain.entity.Email;

public class EmailDTO {

    public EmailDTO() {
    }

    public static Email fromJson(Map<String, Object> email) {

        Email emailRet = new Email(email.get("id").toString(), email.get("author").toString(),
                email.get("receiver").toString(),
                email.get("message").toString(), email.get("subject").toString());

        return emailRet;
    }

    public static Map<String, Object> toJson(Email email) {
        Map<String, Object> emailMap = new HashMap<>();

        emailMap.put("author", email.getAuthor());
        emailMap.put("receiver", email.getReceiver());
        emailMap.put("message", email.getMessage());
        emailMap.put("subject", email.getSubject());
        emailMap.put("id", email.getId());

        return emailMap;
    }
}
