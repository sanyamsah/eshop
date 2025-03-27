import styles from './styles.module.css';
import { useFormik } from 'formik';
import * as Yup from 'yup';
import axios from 'axios';
import { Link } from 'react-router-dom';
import { useState } from 'react';
import Navbar from "../../components/Navbar";

const Registration = () => {
    const initialValues = {
        name: '',
        username: '',
        email: '',
        password: ''
    };

    const [requestResponse, setRequestResponse] = useState({
        requestMessage: "",
        alertClassName: ""
    });

    const onSubmit = async (values) => {
        try {
            const userData = {
                ...values,
                username: values.username,
                email: values.email,
                name: values.name,
                role: 'USER'
            };
            const response = await axios
                .post("http://localhost:8080/api/auth/register", userData)
                .then(
                    (response) => setRequestResponse({
                        requestMessage: "User registered successfully!",
                        alertClassName: "alert alert-success"
                    })
                );
            console.log(response.data);
        } catch (error) {
            console.error(error);
            setRequestResponse({
                requestMessage: error.response.data.message,
                alertClassName: "alert alert-danger"
            })
        }
    };

    const validationSchema = Yup.object({
        name: Yup.string()
            .required("Name is required"),
        username: Yup.string()
            .required("Username is required"),
        email: Yup.string()
            .email("Invalid email format.")
            .required("Email is required."),
        password: Yup.string()
            .required("Password is required.")
            .min(6, "Password length should be at least 6 characters.")
    });

    const formik = useFormik({
        initialValues,
        onSubmit,
        validationSchema,
        validateOnMount: false,
        validateOnBlur: true,
        validateOnChange: true
    });

    return (
        <>
            <Navbar />
            <div className='container' style={{ backgroundColor: '#F2EFE7' }}>
                <div className="row">
                    <div className="col-md-3"></div>
                    <div className="col-md-6">
                        <div className={styles.wrapper} style={{
                            backgroundColor: 'white',
                            padding: '2rem',
                            borderRadius: '8px',
                            boxShadow: '0 2px 10px rgba(0, 106, 113, 0.1)'
                        }}>
                            <div className={requestResponse.alertClassName}
                                role="alert"
                                style={{
                                    backgroundColor: requestResponse
                                        .alertClassName
                                        .includes('success') ? '#d4edda' : '#f8d7da',
                                    color: requestResponse.alertClassName
                                        .includes('success') ? '#155724' : '#721c24',
                                    borderColor: requestResponse
                                        .alertClassName.includes('success') ? '#c3e6cb' : '#f5c6cb'
                                }}>
                                {requestResponse.requestMessage}
                            </div>
                            <h2 className={styles.heading2}
                                style={{ color: '#006A71' }}>
                                Register Here</h2>
                            <form onSubmit={formik.handleSubmit}>
                                <div className="form-group">
                                    <label style={{ color: '#006A71' }}>Name</label>
                                    <input
                                        type="text"
                                        className="form-control"
                                        name="name"
                                        placeholder='Enter full name'
                                        value={formik.values.name}
                                        onChange={formik.handleChange}
                                        style={{ borderColor: '#9ACBD0' }} />
                                    {formik.errors.name ?
                                        <small className='text-danger'>{formik.errors.name}<br /></small> : null}

                                    <label style={{ color: '#006A71' }}>Username</label>
                                    <input
                                        placeholder='Enter valid username'
                                        type="text"
                                        className="form-control"
                                        name="username"
                                        value={formik.values.username}
                                        onChange={formik.handleChange}
                                        style={{ borderColor: '#9ACBD0' }} />
                                    {formik.errors.username ?
                                        <small className='text-danger'>{formik.errors.username}<br /></small> : null}

                                    <label style={{ color: '#006A71' }}>Email</label>
                                    <input
                                        placeholder='Enter valid email'
                                        type="email"
                                        className="form-control"
                                        name="email"
                                        value={formik.values.email}
                                        onChange={formik.handleChange}
                                        style={{ borderColor: '#9ACBD0' }} /> <br />
                                    {formik.errors.email ?
                                        <small className='text-danger'>{formik.errors.email}<br /></small> : null}

                                    <label style={{ color: '#006A71' }}>Password</label>
                                    <input
                                        placeholder='Create strong password'
                                        type="password"
                                        className="form-control"
                                        name="password"
                                        value={formik.values.password}
                                        onChange={formik.handleChange}
                                        style={{ borderColor: '#9ACBD0' }} />
                                    {formik.errors.password ?
                                        <small className='text-danger'>{formik.errors.password}<br /></small> : null}
                                </div>
                                <input
                                    type="submit"
                                    value="Register"
                                    className="btn btn-block"
                                    disabled={!formik.isValid}
                                    style={{
                                        backgroundColor: '#006A71',
                                        color: 'white',
                                        border: 'none'
                                    }}
                                />
                            </form>
                            <br />
                            <p className="text-center" style={{ color: '#006A71' }}>
                                Already Registered? Click Here:
                                <Link to="/login" style={{ color: '#48A6A7' }}>Login</Link>
                            </p>
                        </div>
                    </div>
                    <div className="col-md-3"></div>
                </div>
            </div>
        </>
    );
}

export default Registration;