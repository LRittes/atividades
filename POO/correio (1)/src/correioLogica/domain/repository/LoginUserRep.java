package domain.repository;

import domain.entity.User;

public interface LoginUserRep {
    public User login(User user) throws Exception;
}
