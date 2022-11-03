package negocio;

import java.util.List;

public class User {
    private String name;
    private String email;
    private int id;
    private List<Email> emails;
    private List<Email> newEmails;

    public User(String name, String email) {
        this.name = name;
        this.email = email;
    }

    public void addEmail(Email e) {
        this.emails.add(e);
    }

    public List<Email> getNewEmails() {
        return newEmails;
    }

    public List<Email> getEmails() {
        return emails;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

}
