package data.repository;

import data.DTO.UserDTO;
import data.dataSource.interfaceDB.UserDB;
import domain.entity.User;
import domain.repository.LoginUserRep;

public class LoginUserRepImp implements LoginUserRep {
    private UserDB _db;

    public LoginUserRepImp(UserDB db) {
        this._db = db;
    }

    public User login(User user) throws Exception {
        try {
            return UserDTO.fromJson(_db.getUser(user.getEmail(), user.getPassword()));
        } catch (Exception e) {
            throw new Exception(e.toString());
        }
    };
}
