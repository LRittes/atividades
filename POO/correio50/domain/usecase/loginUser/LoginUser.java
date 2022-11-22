package domain.usecase.loginUser;

import domain.entity.User;

public interface LoginUser {
    public User login(User user) throws Exception;
}
