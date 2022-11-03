package negocio;

import java.util.List;

public class Sistema {
    private User user;

    public User getUser() {
        return user;
    }

    public void addEmail() {
    }

    public void register(String name, String email) {
    }

    public void login(String email, String password) {
    }

    public List<Email> emailsRecebidos() {
        return user.getNewEmails();
    }

    public void enviarEmail(Email e) {
    }

    public void excluirEmail(int id) {
    }

    public void responderEmail(int id, String message) {
    }

}