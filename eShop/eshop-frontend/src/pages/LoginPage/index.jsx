import React, { useState } from 'react';
import axios from 'axios';
import { Formik, Form, ErrorMessage, Field } from 'formik';
import * as Yup from 'yup';
import styles from './styles.module.css';
import { Link, useNavigate } from 'react-router-dom';

const LoginPage = () => {

    const navigate = useNavigate();

    const [requestResponse, setRequestResponse] = useState({
        requestMessage: "",
        alertClassName: ""
    });

    const initialValues = {
        usernameOrEmail: '',
        password: ''
    };

    const onSubmit = async (values) => {
        try {
            const userData = {
                usernameOrEmail: values.usernameOrEmail,
                password: values.password
            };

            const response = await axios.post("http://localhost:8080/api/auth/login", userData);
            console.log("Response Data:", response.data);

            if (!response.data) {
                throw new Error("Token not received from server.");
            }

            setRequestResponse({
                requestMessage: "User logged in successfully!",
                alertClassName: "alert alert-success"
            });

            localStorage.setItem("token", response.data);
            console.log("Token Stored:", localStorage.getItem("token"));

            navigate("/");

        } catch (error) {
            console.error("Login Error:", error);
            setRequestResponse({
                requestMessage: "Invalid email or username or password",
                alertClassName: "alert alert-danger"
            });
        }
    };


    const validationSchema = Yup.object({
        usernameOrEmail: Yup.string()
            .required('Username or Email is required.'),
        password: Yup.string()
            .required('Password is required.')
            .min(6, 'Password should be at least 6 characters long.')
    });

    return (
        <div className="container">
            <div className="row">
                <div className="col-md-3"></div>
                <div className="col-md-6">
                    <div className={styles.wrapper}>
                        <h2>Login</h2>
                        <hr />
                        {requestResponse.requestMessage && (
                            <div className={requestResponse.alertClassName}>
                                {requestResponse.requestMessage}
                            </div>
                        )}
                        <Formik
                            initialValues={initialValues}
                            onSubmit={onSubmit}
                            validationSchema={validationSchema}
                        >
                            {() => (
                                <Form>
                                    <div className="form-group">
                                        <label>Username (or Email)</label>
                                        <Field type="text" name="usernameOrEmail" className="form-control" />
                                        <ErrorMessage name="usernameOrEmail" component="div" className="text-danger" />
                                    </div>

                                    <div className="form-group">
                                        <label>Password</label>
                                        <Field type="password" name="password" className="form-control" />
                                        <ErrorMessage name="password" component="div" className="text-danger" />
                                    </div>

                                    <input type="submit" value="Login" className="btn btn-primary btn-block" />
                                </Form>
                            )}
                        </Formik>
                        <br />
                        <p className="text-center">
                            New User? Register <Link to="/register">Here</Link>
                        </p>
                    </div>
                </div>
                <div className="col-md-3"></div>
            </div>
        </div>
    );
};

export default LoginPage;
