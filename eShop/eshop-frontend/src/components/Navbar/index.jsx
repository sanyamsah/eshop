import { Link, useNavigate } from "react-router-dom";
import React, { useState, useEffect } from "react";

const Navbar = () => {
    const navigate = useNavigate();
    const [isLoggedIn, setIsLoggedIn] = useState(false);

    useEffect(() => {
        let token = localStorage.getItem("token");
        if (!token) {
            setIsLoggedIn(false);
        } else {
            setIsLoggedIn(true);
        }
    }, [isLoggedIn]);

    const onLogoutHandler = () => {
        localStorage.clear();
        setIsLoggedIn(false);
        navigate("/");
    };

    return (
        <nav className="navbar navbar-expand-lg navbar-dark bg-dark">
            <Link className="navbar-brand" to="/">
                EShop
            </Link>
            <button
                className="navbar-toggler"
                type="button"
                data-toggle="collapse"
                data-target="#navbarSupportedContent"
                aria-controls="navbarSupportedContent"
                aria-expanded="false"
                aria-label="Toggle navigation"
            >
                <span className="navbar-toggler-icon"></span>
            </button>

            <div className="collapse navbar-collapse" id="navbarSupportedContent">
                <ul className="navbar-nav mr-auto">
                    <li className="nav-item active">
                        <Link className="nav-link" to="/">
                            Home
                        </Link>
                    </li>
                    <li className="nav-item">
                        <Link className="nav-link" to="/about">
                            About
                        </Link>
                    </li>
                    <li className="nav-item">
                        <Link className="nav-link" to="/products">
                            Product
                        </Link>
                    </li>
                    <li className="nav-item">
                        <Link className="nav-link" to="/contact">
                            Contact
                        </Link>
                    </li>
                </ul>
                <div className="form-inline my-2 my-lg-0">
                    {!isLoggedIn ? (
                        <Link className="btn btn-primary" to={"/login"}>
                            Login
                        </Link>
                    ) : (
                        <button className="btn btn-danger" onClick={onLogoutHandler}>
                            Logout
                        </button>
                    )}

                </div>
            </div>
        </nav>
    );
};
export default Navbar;