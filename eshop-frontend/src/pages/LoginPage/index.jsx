import React, { useState } from 'react';
import axios from 'axios';
import { Formik, Form, ErrorMessage, Field } from 'formik';
import * as Yup from 'yup';
import { Link, useNavigate } from 'react-router-dom';
import Navbar from '../../components/Navbar';

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
            const response = await axios.post("http://localhost:8080/api/auth/login", {
                usernameOrEmail: values.usernameOrEmail,
                password: values.password
            });

            localStorage.setItem("token", response.data);
            setRequestResponse({
                requestMessage: "Login successful! Redirecting...",
                alertClassName: "alert alert-success"
            });

            setTimeout(() => navigate("/"), 1500);
        } catch (error) {
            setRequestResponse({
                requestMessage: "Invalid credentials. Please try again.",
                alertClassName: "alert alert-danger"
            });
        }
    };

    const validationSchema = Yup.object({
        usernameOrEmail: Yup.string().required('Username or Email is required'),
        password: Yup.string()
            .required('Password is required')
            .min(6, 'Password must be at least 6 characters')
    });

    return (
        <>
            <Navbar />
            <div className="container py-5"
                style={{ backgroundColor: '#F2EFE7', minHeight: 'calc(100vh - 56px)' }}>
                <div className="row justify-content-center">
                    <div className="col-lg-6 col-md-8">
                        <div className="bg-white p-4 p-md-5 rounded shadow-sm">
                            <h2 className="text-center mb-4" style={{ color: '#006A71' }}>
                                Login
                            </h2>

                            {requestResponse.requestMessage && (
                                <div className={`${requestResponse.alertClassName} mb-4`}>
                                    {requestResponse.requestMessage}
                                </div>
                            )}

                            <Formik
                                initialValues={initialValues}
                                onSubmit={onSubmit}
                                validationSchema={validationSchema}
                            >
                                {({ isSubmitting }) => (
                                    <Form>
                                        <div className="mb-4">
                                            <label className="form-label" style={{ color: '#006A71' }}>
                                                Username or Email
                                            </label>
                                            <Field
                                                type="text"
                                                name="usernameOrEmail"
                                                className="form-control"
                                                style={{ borderColor: '#006A71' }}
                                            />
                                            <ErrorMessage
                                                name="usernameOrEmail"
                                                component="div"
                                                className="text-danger mt-1"
                                            />
                                        </div>

                                        <div className="mb-4">
                                            <label className="form-label" style={{ color: '#006A71' }}>
                                                Password
                                            </label>
                                            <Field
                                                type="password"
                                                name="password"
                                                className="form-control"
                                                style={{ borderColor: '#006A71' }}
                                            />
                                            <ErrorMessage
                                                name="password"
                                                component="div"
                                                className="text-danger mt-1"
                                            />
                                        </div>

                                        <div className="d-grid gap-3">
                                            <button
                                                type="submit"
                                                className="btn btn-lg"
                                                disabled={isSubmitting}
                                                style={{
                                                    backgroundColor: '#006A71',
                                                    color: 'white',
                                                    border: 'none'
                                                }}
                                                onMouseEnter={(e) => e.target.style.backgroundColor = '#48A6A7'}
                                                onMouseLeave={(e) => e.target.style.backgroundColor = '#006A71'}
                                            >
                                                {isSubmitting ? 'Logging in...' : 'Login'}
                                            </button>

                                            <div className="text-center mt-3">
                                                <p style={{ color: '#006A71' }}>
                                                    New user?
                                                    <Link to="/register" style={{ color: '#48A6A7' }}>
                                                        Register here</Link>
                                                </p>
                                            </div>
                                        </div>
                                    </Form>
                                )}
                            </Formik>
                        </div>
                    </div>
                </div>
            </div>
        </>
    );
};

export default LoginPage;