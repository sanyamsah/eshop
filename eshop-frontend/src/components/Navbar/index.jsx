import { Link, useNavigate } from "react-router-dom";
import React, { useState, useEffect } from "react";

const Navbar = () => {
    const navigate = useNavigate();
    const [isLoggedIn, setIsLoggedIn] = useState(false);

    useEffect(() => {
        const token = localStorage.getItem("token");
        setIsLoggedIn(!!token);
    }, []);

    const onLogoutHandler = () => {
        localStorage.clear();
        setIsLoggedIn(false);
        navigate("/");
    };

    return (
        <nav className="navbar navbar-expand-lg navbar-dark" style={{ backgroundColor: "#006A71" }}>
            <div className="container">
                <Link className="navbar-brand" to="/" style={{ color: "#F2EFE7" }}>
                    EShop
                </Link>
                <button
                    className="navbar-toggler"
                    type="button"
                    data-bs-toggle="collapse"
                    data-bs-target="#navbarSupportedContent"
                    aria-controls="navbarSupportedContent"
                    aria-expanded="false"
                    aria-label="Toggle navigation"
                >
                    <span className="navbar-toggler-icon"></span>
                </button>

                <div className="collapse navbar-collapse" id="navbarSupportedContent">
                    <ul className="navbar-nav me-auto">
                        <li className="nav-item">
                            <Link 
                                className="nav-link" 
                                to="/" 
                                style={{ color: "#F2EFE7" }}
                                onMouseOver={(e) => e.target.style.color = "#9ACBD0"}
                                onMouseOut={(e) => e.target.style.color = "#F2EFE7"}
                            >
                                Home
                            </Link>
                        </li>
                        <li className="nav-item">
                            <Link 
                                className="nav-link" 
                                to="/about" 
                                style={{ color: "#F2EFE7" }}
                                onMouseOver={(e) => e.target.style.color = "#9ACBD0"}
                                onMouseOut={(e) => e.target.style.color = "#F2EFE7"}
                            >
                                About
                            </Link>
                        </li>
                        <li className="nav-item">
                            <Link 
                                className="nav-link" 
                                to="/products" 
                                style={{ color: "#F2EFE7" }}
                                onMouseOver={(e) => e.target.style.color = "#9ACBD0"}
                                onMouseOut={(e) => e.target.style.color = "#F2EFE7"}
                            >
                                Products
                            </Link>
                        </li>
                        <li className="nav-item">
                            <Link 
                                className="nav-link" 
                                to="/contact" 
                                style={{ color: "#F2EFE7" }}
                                onMouseOver={(e) => e.target.style.color = "#9ACBD0"}
                                onMouseOut={(e) => e.target.style.color = "#F2EFE7"}
                            >
                                Contact
                            </Link>
                        </li>
                    </ul>
                    <div className="d-flex">
                        {!isLoggedIn ? (
                            <Link 
                                className="btn btn-outline-light me-2" 
                                to="/login"
                                style={{
                                    backgroundColor: "transparent",
                                    borderColor: "#F2EFE7",
                                    color: "#F2EFE7"
                                }}
                                onMouseOver={(e) => {
                                    e.target.style.backgroundColor = "#9ACBD0";
                                    e.target.style.borderColor = "#9ACBD0";
                                    e.target.style.color = "#006A71";
                                }}
                                onMouseOut={(e) => {
                                    e.target.style.backgroundColor = "transparent";
                                    e.target.style.borderColor = "#F2EFE7";
                                    e.target.style.color = "#F2EFE7";
                                }}
                            >
                                Login
                            </Link>
                        ) : (
                            <button 
                                className="btn btn-outline-light" 
                                onClick={onLogoutHandler}
                                style={{
                                    backgroundColor: "transparent",
                                    borderColor: "#F2EFE7",
                                    color: "#F2EFE7"
                                }}
                                onMouseOver={(e) => {
                                    e.target.style.backgroundColor = "#9ACBD0";
                                    e.target.style.borderColor = "#9ACBD0";
                                    e.target.style.color = "#006A71";
                                }}
                                onMouseOut={(e) => {
                                    e.target.style.backgroundColor = "transparent";
                                    e.target.style.borderColor = "#F2EFE7";
                                    e.target.style.color = "#F2EFE7";
                                }}
                            >
                                Logout
                            </button>
                        )}
                    </div>
                </div>
            </div>
        </nav>
    );
};

export default Navbar;